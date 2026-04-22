# -*- coding: utf-8 -*-
import os
import requests
import json
import time
import re

# GitHub Actions 환경변수에서 설정값 가져오기
NOTION_TOKEN = os.environ.get('NOTION_TOKEN')
NOTION_PAGE_ID = os.environ.get('NOTION_PAGE_ID')

RequestTime = 10  # API 요청 간격 (초 단위)

headers = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}

# 403 문제로 방식 변경
def get_solved_ac_info(prob_id):
    """Solved.ac API를 통해 문제 정보(제목, 티어, 태그) 획득"""
    url = f"https://solved.ac/api/v3/problem/show?problemId={prob_id}"

    #브라우저인 척 변장하기
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
        "Content-Type": "application/json",
        "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7",
        "Referer": "https://solved.ac/",
        "Origin": "https://solved.ac"
    }

    try:
        res = requests.get(url, headers=headers)
        print(f"📡 Solved.ac 응답 코드 [{prob_id}]: {res.status_code}")
        if res.status_code == 200:
            data = res.json()
            return {
                "title": data.get("titleKo"),
                "level": data.get("level"), # 티어 숫자 (예: 11 -> Gold 5)
                "tags": [tag['displayNames'][0]['name'] for tag in data.get("tags", [])]
            }
    except Exception as e:
        print(f"Solved.ac API 호출 중 오류 발생: {e}")
    return None

# Readme.md 파일에서 티어, 제목, 번호를 추출하는 함수
def parse_readme_data(readme_path):
    """README.md의 내용을 분석하여 문제 정보를 추출"""
    try:
        with open(readme_path, "r", encoding="utf-8") as f:
            content = f.read()
            
            # 1. 티어, 제목, 번호 추출 (첫 번째 줄)
            # 패턴: # [티어] 제목 - 번호
            header_match = re.search(r'# \[(.*?)\] (.*?) - (\d+)', content)
            
            # 2. 분류(태그) 추출
            # 패턴: ### 분류\n\n태그1, 태그2...
            tag_match = re.search(r'### 분류\s*\n\n(.*?)\n', content)
            
            if header_match:
                return {
                    "level_name": header_match.group(1), # "Bronze V"
                    "title": header_match.group(2),      # "A+B"
                    "prob_id": header_match.group(3),    # "1000"
                    "tags": tag_match.group(1).split(", ") if tag_match else ["분류 없음"]
                }
    except Exception as e:
        print(f"❌ README 분석 중 오류: {e}")
    return None

# 티어 문자열을 숫자로 변환하는 함수
def get_level_num(level_name):
    """Bronze V 같은 문자열을 Solved.ac 레벨 숫자로 변환"""
    tiers = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby"]
    ranks = {"V": 1, "IV": 2, "III": 3, "II": 4, "I": 5}
    
    try:
        tier_part, rank_part = level_name.split()
        tier_idx = tiers.index(tier_part)
        return (tier_idx * 5) + ranks[rank_part]
    except:
        return 0 # 알 수 없는 경우 0 (Unrated)


def create_notion_page(prob_id, info, code):
    """노션 API를 호출하여 페이지 구성 및 생성"""
    url = "https://api.notion.com/v1/pages"
    
    #[페이지 아이콘]: Solved.ac 티어 이미지를 URL로 설정
    icon_url = f"https://d2gd6pc034wcta.cloudfront.net/tier/{info['level']}.svg"
    
    payload = {
        #[부모 설정]: 이 페이지가 생성될 노션의 상위 페이지 ID
        "parent": {"page_id": NOTION_PAGE_ID},
        
        #[아이콘]: 페이지 상단에 표시될 티어 아이콘
        "icon": {"type": "external", "external": {"url": icon_url}},
        
        #[제목]: 페이지 제목: "문제번호 - 문제제목"
        "properties": {
            "title": {"title": [{"text": {"content": f"{prob_id} - {info['title']}"}}]}
        },
        
        #[본문]: 페이지 내부에 들어갈 내용 블록들
        "children": [
            # 1. 강조 박스 (Callout): 문제 태그 정보 표시
            {
                "object": "block",
                "type": "callout",
                "callout": {
                    "rich_text": [{"text": {"content": f"알고리즘 분류: {', '.join(info['tags'])}"}}]
                }
            },
            # 2. 텍스트 (Paragraph): 백준 문제 링크 추가
            {
                "object": "block",
                "type": "paragraph",
                "paragraph": {
                    "rich_text": [
                        {
                            "text": {
                                "content": "? 백준 문제 바로가기",
                                "link": {"url": f"https://www.acmicpc.net/problem/{prob_id}"}
                            }
                        }
                    ]
                }
            },
            # 3. 구분선 (Divider)
            {
                "object": "block",
                "type": "divider",
                "divider": {}
            },
            # 4. 코드 블록 (Code Block): C++ 코드 삽입
            {
                "object": "block",
                "type": "code",
                "code": {
                    "language": "cpp",
                    "rich_text": [{"text": {"content": code}}]
                }
            }
        ]
    }
    
    res = requests.post(url, headers=headers, json=payload)
    if res.status_code == 200:
        print(f"성공: {prob_id} 페이지 생성 완료")
    else:
        print(f"실패: {prob_id} (에러 코드: {res.status_code})")
        print(res.text)

def main():
    # 현재 디렉토리부터 하위 폴더를 모두 탐색
    for root, dirs, files in os.walk("."):
        # 불필요한 설정 폴더(.git, .github)는 건너뜀
        if ".git" in root or ".github" in root:
            continue
            
        for file in files:
            # 1. 확장자 체크: .cpp 뿐만 아니라 .cc 파일도 포함
            if file.endswith(".cpp") or file.endswith(".cc"):

                # 2-1. 문제 정보가 있는 README.md 파일 경로
                readme_path = os.path.join(root, "README.md")

                if os.path.exists(readme_path):
                    #2.1 README.md 파일에서 문제 정보 추출 
                    readme_info = parse_readme_data(readme_path)

                    # 2-2. 파일 내용 파싱 
                    if readme_info:
                        level_num = get_level_num(readme_info['level_name'])

                        info = {
                            "title": readme_info['title'],
                            "level": level_num,
                            "tags": readme_info['tags']
                        }
                        prob_id = readme_info['prob_id']
                    else:
                        print(f"⚠️ README 분석 실패: {root}")
                        continue
                else:
                    print(f"⚠️ README.md 파일이 없습니다: {root}")
                    continue
                
                # 3. 문제 번호를 찾았다면 노션 업로드 진행
                if prob_id:
                    print(f"🚀 노션 업로드 중: {prob_id} - {info['title']}")
                    #info = get_solved_ac_info(prob_id)

                    # 소스 코드 파일 읽기
                    file_path = os.path.join(root, file)
                    with open(file_path, "r", encoding="utf-8") as f:
                        code_content = f.read()
                        
                    # 노션에 페이지 생성 함수 호출
                    status = create_notion_page(prob_id, info, code_content)
                    if status == 200 or status == 201:
                        print(f"✅ 업로드 완료: {prob_id} (Status: {status})")
                    else:
                        print(f"❌ 노션 전송 실패: {prob_id} (에러 코드: {status})")

                    time.sleep(RequestTime)
                else:
                    print(f"⚠️ 스킵됨: README.md 정보가 부족하거나 형식이 맞지 않음 (위치: {root})")

# GitHub Actions에서 직접 실행할 때는 main() 함수를 호출
if __name__ == "__main__":
    main()