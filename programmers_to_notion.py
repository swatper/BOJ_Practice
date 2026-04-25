import os
import re
import time
import requests

# API 요청 간격 (초 단위)
RequestTime = 1

# 1. 프로그래머스 README 파싱 (핵심 정보 추출)
def parse_programmers_readme(readme_path):
    try:
        with open(readme_path, "r", encoding="utf-8") as f:
            content = f.read()
            
            # 헤더 추출: # [level 0] 제목 - 340207
            header_match = re.search(r'# \[level (\d+)\] (.*?) - (\d+)', content)
            # 구분(카테고리) 추출: ### 구분\n\n내용
            tag_match = re.search(r'### 구분\s*\n\n(.*?)\n', content)
            # 성능 요약 추출 (메모리, 시간)
            perf_match = re.search(r"메모리: (.*?), 시간: (.*?)\n", content)
            
            if header_match:
                full_category = tag_match.group(1) if tag_match else "미분류"
                # '코딩테스트 연습 > 해시' -> '해시'만 추출
                last_category = full_category.split(' > ')[-1].strip()
                performance = perf_match.group(0).strip() if perf_match else ""

                return {
                    "level": header_match.group(1),
                    "title": header_match.group(2).strip(),
                    "prob_id": header_match.group(3),
                    "tags": [last_category],
                    "performance": performance,
                    "full_content": content # 블록 생성용
                }
    except Exception as e:
        print(f"? README 분석 오류: {e}")
    return None

# 2. 노션 페이지 본문 블록 생성
def build_programmers_blocks(info, code):
    blocks = [
        {
            "object": "block",
            "type": "callout",
            "callout": {
                "rich_text": [
                    {"text": {"content": f"알고리즘 분류: {', '.join(info['tags'])}\n"}},
                    {"text": {"content": f"? {info['performance']}"}}
                ],
                "icon": {"type": "emoji", "emoji": "?"}
            }
        },
        {
            "object": "block",
            "type": "paragraph",
            "paragraph": {
                "rich_text": [{
                    "text": {
                        "content": "? 프로그래머스 문제 링크 바로가기",
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
                "language": "cpp",
                "rich_text": [
                    {"type": "text", "text": {"content": code[i : i + 2000]}} 
                    for i in range(0, len(code), 2000)
                ]
            }
        }
    ]
    return blocks

# 3. 노션 업로드 (데이터베이스 행 생성)
def upload_to_notion(info, content_blocks, config, headers):
    url = "https://api.notion.com/v1/pages"
    level_emojis = {"0": "?", "1": "?", "2": "?", "3": "?", "4": "?", "5": "?"}
    
    payload = {
        "parent": {"database_id": config['NOTION_DATABASE_ID_PROG']},
        "icon": {"type": "emoji", "emoji": level_emojis.get(info['level'], "?")},
        "properties": {
            "문제 이름": {"title": [{"text": {"content": f" {info['title']}"}}]},
            "문제 번호": {"rich_text": [{"text": {"content": str(info['prob_id'])}}]},
            "알고리즘": {"multi_select": [{"name": tag} for tag in info['tags']]},
            "플랫폼": {"select": {"name": "Programmers"}},
            "난이도": {"select": {"name": f"Lv.{info['level']}"}}
        },
        "children": content_blocks 
    }
    return requests.post(url, headers=headers, json=payload)

# 4. 중복 체크 함수 (기존 코드 활용)
def check_if_exists(prob_id, config, headers):
    url = f"https://api.notion.com/v1/databases/{config['NOTION_DATABASE_ID_PROG']}/query"
    filter_data = {"filter": {"property": "문제 번호", "rich_text": {"equals": str(prob_id)}}}
    res = requests.post(url, headers=headers, json=filter_data)
    return len(res.json().get("results", [])) > 0 if res.status_code == 200 else False

# 5. 메인 실행 프로세스
def run_programmers_process(base_path, config, headers):
    for root, dirs, files in os.walk(base_path):
        for file in files:
            # 소스코드 파일 검색 (.cpp, .cc 등)
            if file.endswith((".cpp", ".cc", ".py", ".java")):
                readme_path = os.path.join(root, "README.md")
                if not os.path.exists(readme_path): continue

                info = parse_programmers_readme(readme_path)
                if not info: continue

                # 중복 확인
                if check_if_exists(info['prob_id'], config, headers):
                    print(f"? 스킵: {info['prob_id']} - {info['title']} (이미 존재)")
                    continue

                # 코드 읽기 및 업로드
                with open(os.path.join(root, file), "r", encoding="utf-8") as f:
                    code_content = f.read()

                print(f"? 업로드 중: {info['prob_id']} - {info['title']}")
                blocks = build_programmers_blocks(info, code_content)
                res = upload_to_notion(info, blocks, config, headers)

                if res.status_code == 200:
                    print(f"? 성공: {info['title']}")
                else:
                    print(f"? 실패: {res.status_code}")
                

    print("? 프로그래머스 문제 업로드 프로세스 완료!")