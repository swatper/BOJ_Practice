import os
import re
import time
import requests

# API 요청 간격 (초 단위)
RequestTime = 1
asset_dir = './assets/'

#프로그래머스 README 파싱 (핵심 정보 추출)
def parse_programmers_readme(readme_path):
    try:
        with open(readme_path, "r", encoding="utf-8") as f:
            content = f.read()
            
            # 헤더 추출: # [level 0] 제목 - 340207
            header_match = re.search(r'# \[level (\d+)\] (.*?) - (\d+)', content)
            # 구분(카테고리) 추출: ### 구분\n\n내용
            tag_match = re.search(r'### 구분\s*\n\n(.*?)\n', content)
            
            if header_match:
                full_category = tag_match.group(1) if tag_match else "미분류"
                # '코딩테스트 연습 > 해시' -> '해시'만 추출
                last_category = full_category.split(' > ')[-1].strip()

                return {
                    "level": header_match.group(1),
                    "title": header_match.group(2).strip(),
                    "prob_id": header_match.group(3),
                    "tags": [last_category],
                    "full_content": content # 블록 생성용
                }
    except Exception as e:
        print(f"    ❌ README 분석 오류: {e}")
    return None

#노션 페이지 본문 블록 생성
def build_programmers_blocks(info, code, ext):
    language_map = {
        ".cpp": "c++",
        ".cc": "c++",
        ".cs": "c#",
        ".sql": "sql",
        ".py": "python",
        ".java": "java",
    }
    notion_language = language_map.get(ext, "plain text")

    #노션 코드 블록 생성 (2000자씩 분할)
    blocks = [
        {
            "object": "block",
            "type": "callout",
            "callout": {
                "rich_text": [
                    {"text": {"content": f"알고리즘 분류: {', '.join(info['tags'])}"}}
                ],
                "icon": {"type": "emoji", "emoji": "💡"}
            }
        },
        {
            "object": "block",
            "type": "paragraph",
            "paragraph": {
                "rich_text": [{
                    "text": {
                        "content": "🚀  프로그래머스 문제 링크 바로가기",
                        "link": {"url": f"https://school.programmers.co.kr/learn/courses/30/lessons/{info['prob_id']}"}
                    }
                }]
            }
        },
        {"object": "block", "type": "divider", "divider": {}},
        {
            "object": "block",
            "type": "code",
            "code": {
                "language": notion_language,
                "rich_text": [
                    {"type": "text", "text": {"content": code[i : i + 2000]}} 
                    for i in range(0, len(code), 2000)
                ]
            }
        }
    ]
    return blocks

# def get_level_icon(level):


#노션 업로드 (데이터베이스 행 생성)
def upload_to_notion(info, content_blocks, config, headers):
    url = "https://api.notion.com/v1/pages"
    level_emojis = {
        "0": "🌱", 
        "1": "⭐", 
        "2": "🔥", 
        "3": "🏆", 
        "4": "💎", 
        "5": "👑"
    }
    
    payload = {
        "parent": {"database_id": config['NOTION_DATABASE_ID_PROG']},
        "icon": {"type": "emoji", "emoji": level_emojis.get(info['level'], "💡")},
        "properties": {
            "문제 이름": {"title": [{"text": {"content": f" {info['title']}"}}]},
            "문제 번호": {"rich_text": [{"text": {"content": str(info['prob_id'])}}]},
            "알고리즘": {"multi_select": [{"name": tag} for tag in info['tags']]}
        },
        "children": content_blocks 
    }
    return requests.post(url, headers=headers, json=payload)

#중복 체크 함수
def get_all_existing_prog_ids(config, headers):
    # ID 전처리: 하이픈 제거 및 공백 제거
    db_id = config['NOTION_DATABASE_ID_PROG'].strip().replace("-", "")
    url = f"https://api.notion.com/v1/databases/{db_id}/query"
    existing_ids = set()
    next_cursor = None

    print("    🔍 노션에서 전체 프로그래머스 목록을 불러오는 중...")

    while True:
        payload = {"page_size": 100}
        if next_cursor:
            payload["start_cursor"] = next_cursor
            
        res = requests.post(url, headers=headers, json=payload)
        if res.status_code != 200:
            print(f"        ❌ 목록 로딩 실패: {res.status_code}")
            break
            
        data = res.json()
        for page in data.get("results", []):
            props = page.get("properties", {})
            # 프로그래머스 DB의 '문제 번호' 열 데이터를 가져옵니다.
            target_prop = props.get("문제 번호", {})
            p_type = target_prop.get("type") # rich_text 또는 title
            
            if p_type and target_prop.get(p_type):
                existing_ids.add(target_prop[p_type][0]["plain_text"])
        
        if not data.get("has_more"): break
        next_cursor = data.get("next_cursor")
        
    print(f"        ✅ 총 {len(existing_ids)}개의 문제 확인")
    return existing_ids



# 5. 메인 실행 프로세스
def run_programmers_process(base_path, config, headers):
    existing_prog_ids = get_all_existing_prog_ids(config, headers)

    for root, dirs, files in os.walk(base_path):
        for file in files:
            # 소스코드 파일 검색
            if file.endswith((".cpp", ".sql")):
                readme_path = os.path.join(root, "README.md")
                if not os.path.exists(readme_path): continue

                info = parse_programmers_readme(readme_path)
                if not info: continue
                                
                print(f"    🚀 업로드 중: {info['prob_id']} - {info['title']}")

                # 중복 확인
                if str(info['prob_id']) in existing_prog_ids:
                    print(f"        ⏩ 스킵: {info['prob_id']} - {info['title']}는 이미 노션에 있음")
                    continue

                # 코드 읽기 및 업로드
                with open(os.path.join(root, file), "r", encoding="utf-8") as f:
                    code_content = f.read()

                blocks = build_programmers_blocks(info, code_content, os.path.splitext(file)[1])
                res = upload_to_notion(info, blocks, config, headers)

                if res.status_code == 200:
                    print(f"        ✅ 성공: {info['title']}")
                else:
                    print(f"        ❌ 실패: {res.status_code}")
                    print(f"        응답 내용: {res.text}")

    print("🎉 프로그래머스 문제 업로드 프로세스 완료!")