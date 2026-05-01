# -*- coding: utf-8 -*-
import os
import requests
import json
import time
import re
import baekjoon_to_notion as boj
import programmers_to_notion as prg

#GitHub Actions 환경변수에서 설정값 가져오기
NOTION_CONFIG = {
    "NOTION_API": os.environ.get('NOTION_API'),
    "NOTION_PAGE_ID": os.environ.get('NOTION_PAGE_ID'),
    "NOTION_DATABASE_ID_BOJ": os.environ.get('NOTION_DATABASE_ID_BOJ'),
    "NOTION_DATABASE_ID_PROG": os.environ.get('NOTION_DATABASE_ID_PROG')
}

headers = {
    "Authorization": f"Bearer {NOTION_CONFIG['NOTION_API']}",
    "Content-Type": "application/json",
    "Notion-Version": "2022-06-28"
}


def main():
    run_mode = os.environ.get('RUN_MODE', 'init')
    base_paths = ["./백준", "./프로그래머스"] 
    if run_mode == 'init':
        print("🚀 초기화 모드로 실행 중...")
        # 현재 디렉토리부터 하위 폴더를 모두 탐색
        for base_path in base_paths:
            if not os.path.exists(base_path):
                print(f"❌ 폴더를 찾을 수 없습니다: {base_path}")
                return
            else:
                if base_path == "./백준":
                    print(f"📂 백준 폴더 탐색 시작: {base_path}")
                    print("⏩ 백준 서비스 종료로 인해 스킵")
                    # boj.run_baekjoon_process(base_path, NOTION_CONFIG, headers)

                elif base_path == "./프로그래머스":
                    print(f"📂 프로그래머스 폴더 탐색 시작: {base_path}")
                    prg.run_programmers_process(base_path, NOTION_CONFIG, headers)
    elif run_mode == 'baekjoon':
        print("🚀 백준 문제 업데이트 모드로 실행 중...")
        base_path = base_paths[0]
        boj.run_baekjoon_process(base_path, NOTION_CONFIG, headers)

    elif run_mode == 'programmers':
        print("🚀 프로그래머스 문제 업데이트 모드로 실행 중...")
        base_path = base_paths[1]
        prg.run_programmers_process(base_path, NOTION_CONFIG, headers)
    else:
        print(f"❌ 알 수 없는 실행 모드: {run_mode}.")


# GitHub Actions에서 직접 실행할 때는 main() 함수를 호출
if __name__ == "__main__":
    main()