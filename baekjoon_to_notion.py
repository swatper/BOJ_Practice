# -*- coding: utf-8 -*-
import os
import json
import time
import re
import requests

RequestTime = 1 # API 요청 간격 (초 단위)

""" 403 문제로 방식 변경
# Solved.ac API로 문제 정보 획득 
def get_solved_ac_info(prob_id):
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
        print(f"? Solved.ac 응답 코드 [{prob_id}]: {res.status_code}")
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
"""


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
        return 0 # 알 수 없는 경우 0


#region 노션 관련 함수
# 노션 API로 페이지 구성
def build_notion_content_blocks(prob_id, info, code):
    """페이지 본문에 들어갈 블록(Callout, Link, Code) 리스트 생성"""
    blocks = [
        # 1. 강조 박스 (알고리즘 태그)
        {
            "object": "block",
            "type": "callout",
            "callout": {
                "rich_text": [{"text": {"content": f"알고리즘 분류: {', '.join(info['tags'])}"}}],
                "icon": {"type": "emoji", "emoji": "💡"}
            }
        },
        # 2. 문제 링크
        {
            "object": "block",
            "type": "paragraph",
            "paragraph": {
                "rich_text": [{
                    "text": {
                        "content": "🚀 백준 문제 링크 바로가기",
                        "link": {"url": f"https://www.acmicpc.net/problem/{prob_id}"}
                    }
                }]
            }
        },
        # 3. 구분선
        {"object": "block", "type": "divider", "divider": {}},
        # 4. 소스 코드 블록 (2000자 제한 대응)
        {
            "object": "block",
            "type": "code",
            "code": {
                "language": "c++",
                "rich_text": [
                    {"type": "text", "text": {"content": code[i : i + 2000]}} 
                    for i in range(0, len(code), 2000)
                ]
            }
        }
    ]
    return blocks
  
#노션 데이터베이스 중복 확인
def check_if_exists(prob_id, config, headers):
    url = f"https://api.notion.com/v1/databases/{config['NOTION_DATABASE_ID_BOJ']}/query"
    filter_data = {
        "filter": {
            "property": "문제 번호",  
            "rich_text": {
                "equals": str(prob_id)
            }
        }
    }
    res = requests.post(url, headers=headers, json=filter_data)
    if res.status_code == 200:
        # 결과 리스트가 비어있지 않으면 이미 존재하는 것
        return len(res.json().get("results", [])) > 0
    return False
  
#노션 데이터베이스 ROW 생성 및 페이지 작성
def upload_to_notion_db(prob_id, info, content_blocks, config, headers):
    """준비된 데이터와 블록을 노션 데이터베이스에 업로드"""
    url = "https://api.notion.com/v1/pages"
    icon_url = f"https://d2gd6pc034wcta.cloudfront.net/tier/{info['level']}.svg"

    payload = {
        #속성 - 제목, 번호, 알고리즘 태그
        "parent": {"database_id": config['NOTION_DATABASE_ID_BOJ']},
        "icon": {"type": "external", "external": {"url": icon_url}},
        "properties": {
            "문제 이름": {"title": [{"text": {"content": f" {info['title']}"}}]},
            "문제 번호": {"rich_text": [{"text": {"content": str(prob_id)}}]},
            "알고리즘": {"multi_select": [{"name": tag} for tag in info['tags']]}
        },
        #페이지
        "children": content_blocks 
    }

    res = requests.post(url, headers=headers, json=payload)
    return res
  
  #endregion

def run_baekjoon_process(base_path, notion_config, headers):
    for root, dirs, files in os.walk(base_path):
        for file in files:
            prob_id = None
            
            # 1. 확장자 체크: .cpp 뿐만 아니라 .cc 파일도 포함
            if file.endswith(".cpp") or file.endswith(".cc") or file.endswith(".sh"):
                # 2. 문제 정보가 있는 README.md 파일 경로
                readme_path = os.path.join(root, "README.md")
                

                if os.path.exists(readme_path):
                    #2.1 README.md 파일에서 문제 정보 추출 
                    readme_info = parse_readme_data(readme_path)

                    # 2-2. 파일 내용 파싱 
                    if readme_info:
                        prob_id = readme_info['prob_id']
                        level_num = get_level_num(readme_info['level_name'])

                        info = {
                            "title": readme_info['title'],
                            "level": level_num,
                            "tags": readme_info['tags']
                        }
                    else:
                        print(f"❌ README 분석 실패: {root}")
                        continue
                else:
                    print(f"❌ README.md 파일이 없습니다: {root}")
                    continue
                
                # 3. 문제 정보를 찾았다면 노션 업로드 진행
                if prob_id:
                    print(f"🚀 노션 업로드 중: {prob_id} - {info['title']}")
                    #info = get_solved_ac_info(prob_id)

                    # 3.1 소스 코드 파일 읽기
                    file_path = os.path.join(root, file)
                    with open(file_path, "r", encoding="utf-8") as f:
                        code_content = f.read()

                    # 3.2 페이지에 들어갈 내용 생성
                    blocks = build_notion_content_blocks(prob_id, info, code_content)

                    # 노션 데이터베이스 중복 확인
                    if check_if_exists(prob_id, config=notion_config, headers=headers):
                        print(f"⏩ 스킵: {prob_id}는 이미 노션에 있습니다.")
                        continue
                    
                    # 3.4 데이터베이스에 작성
                    res = upload_to_notion_db(prob_id, info, blocks, config=notion_config, headers=headers)

                    if res.status_code == 200:
                        print(f"✅ 성공: {prob_id} 페이지 생성 완료")
                    else:
                        print(f"❌ 실패: {prob_id} (에러: {res.status_code})")
                    
                    # API 과부하 방지를 위한 대기
                    time.sleep(RequestTime)
                else:
                    print(f"⚠️ 스킵됨: README.md 정보가 부족하거나 형식이 맞지 않음 (위치: {root})")
    print("🎉 백준 문제 업로드 프로세스 완료!")
