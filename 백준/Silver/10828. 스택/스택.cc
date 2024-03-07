	#include <iostream>
	#include <string>
	using namespace std;

	int main() {
		int N;	     //명령어 수
		int Top = 0; //스텍의 맨 위 인덱스를 가리키는 변수
		cin >> N;
		int *MyStack = new int [N];// 스텍
		for (int i = 0; i < N; i++) {
			int data;			//입력 받을 숫자
			string Cmd;			//입력 받을 명령어 
			cin >> Cmd;			//명령어입력 받기

				/*스텍에서 top이 0이면 스텍은 비어았는 상태*/
			if (Cmd == "push") {	//데이터 삽입
				cin >> data;		//데이터 입력받기
				MyStack[Top] = data;//스텍에 추가
				Top++;				//맨 위의 인덱스 증가
			}

			if (Cmd =="pop") {	//데이터 삭제
				if (Top == 0) {
					cout << -1 << endl;
				}
				else {
					cout << MyStack[Top - 1] << endl;
					MyStack[Top - 1] = -1;
					Top--;//맨 위의 인덱스 감소
				}
			}

			if (Cmd == "size") {	//데이터 갯수
				cout << Top << endl; //맨 위 인덱스 == 데이터 갯수
			}

			if (Cmd == "empty") {	//데이터 공간 여부
				if (Top == 0) {		
					cout << 1 << endl;
				}
				else {
					cout << 0 << endl;
				}
			}

			if (Cmd == "top") {		//가장 최근에 들어온 데이터
				if (Top == 0) {		
					cout << -1 << endl;
				}
				else {
					cout << MyStack[Top-1] << endl;//인덱스가 1 높기때문에 1을 줄여야 맨 위의 데이터 출력
				}
			}
		}
		delete[] MyStack;
		return 0;
	}