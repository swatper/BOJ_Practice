# -*- coding: utf-8 -*-
import os
import requests
import json
import time

# GitHub Actions 환경변수에서 설정값 가져오기
NOTION_TOKEN = os.environ.get('NOTION_TOKEN')
NOTION_PAGE_ID = os.environ.get('NOTION_PAGE_ID')

RequestTime = 10  # API 요청 간격 (초 단위)

headers = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}

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
                    "rich_text": [{"text": {"content": f"알고리즘 분류: {', '.join(info['tags'])}"}}],
                    "icon": {"emoji": "?"}
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
                
                # 2. 문제 번호 추출: 파일명이 아닌 '부모 폴더명'에서 가져옴
                # root.split(os.sep)[-1]은 현재 파일이 들어있는 폴더 이름(예: "1263. 시간 관리")입니다.
                parent_folder = root.split(os.sep)[-1]
                
                # 폴더명의 시작 부분에서 숫자만 추출 (예: "1263. 시간 관리" -> "1263")
                prob_id = ""
                for char in parent_folder:
                    if char.isdigit():
                        prob_id += char
                    else:
                        # 숫자가 아닌 문자(. 이나 공백 등)를 만나면 추출 중단
                        if prob_id: break
                
                # 3. 문제 번호를 찾았다면 노션 업로드 진행
                if prob_id:
                    print(f"🚀 분석 중인 문제: {prob_id}")
                    info = get_solved_ac_info(prob_id)
                    
                    if info:
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
                        print(f"⚠️ Solved.ac 정보를 가져오지 못했습니다: {prob_id}")
                        time.sleep(RequestTime)
                else:
                    print(f"⚠️ 문제 번호 추출 실패: {parent_folder} (파일: {file})")

# GitHub Actions에서 직접 실행할 때는 main() 함수를 호출
if __name__ == "__main__":
    main()