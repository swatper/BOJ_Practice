# -*- coding: utf-8 -*-
import os
import requests
import json

# GitHub Actions 환경변수에서 설정값 가져오기
NOTION_TOKEN = os.environ.get('NOTION_TOKEN')
NOTION_PAGE_ID = os.environ.get('NOTION_PAGE_ID')

headers = {
    "Authorization": f"Bearer {NOTION_TOKEN}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}

def get_solved_ac_info(prob_id):
    """Solved.ac API를 통해 문제 정보(제목, 티어, 태그) 획득"""
    url = f"https://solved.ac/api/v3/problem/show?problemId={prob_id}"
    try:
        res = requests.get(url)
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
    #깃허브 레포지토리 내의 모든 폴더/파일 탐색
    for root, dirs, files in os.walk("."):
        #불필요한 설정 폴더 제외
        if ".git" in root or ".github" in root:
            continue
            
        for file in files:
            #C++ 소스 파일만 처리
            if file.endswith(".cpp"):
                #파일 경로 또는 이름에서 문제 번호 추출 (예: '5639.cpp' 또는 '5639 - 이진 검색 트리' 폴더 내 파일)
                #숫자로만 구성된 부분만 추출하여 문제 번호로 사용
                prob_id = "".join(filter(str.isdigit, file))
                
                # 만약 파일명에 번호가 없다면 부모 폴더 이름에서 시도
                if not prob_id:
                    parent_folder = root.split(os.sep)[-1]
                    prob_id = "".join(filter(str.isdigit, parent_folder))
                
                if prob_id:
                    print(f"문제 {prob_id} 분석 중...")
                    info = get_solved_ac_info(prob_id)
                    
                    if info:
                        # 소스 코드 파일 읽기
                        file_path = os.path.join(root, file)
                        with open(file_path, "r", encoding="utf-8") as f:
                            code_content = f.read()
                        
                        # 노션에 페이지 생성
                        create_notion_page(prob_id, info, code_content)

if __name__ == "__main__":
    main()