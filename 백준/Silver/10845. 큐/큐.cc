#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;	     //명령어 수
	int front = 0; //큐의 맨 앞
	int back = 0; //큐의 맨 뒤
	cin >> N;
	int* MyQueue = new int[N];// 스텍
	for (int i = 0; i < N; i++) {
		int data;			//입력 받을 숫자
		string Cmd;			//입력 받을 명령어 
		cin >> Cmd;			//명령어입력 받기
		//push 명령어
		if(Cmd == "push") {
			cin >> data;
			MyQueue[back] = data;
			back++;
		}
		//pop 명령어
		if (Cmd == "pop") {
			//맨 앞을 가리키는 인덱스와 맨 뒤를 가리키는 인덱스가 같으면 비어있음
			if (back == 0 || front == back) {
				cout << -1 << "\n";
			}
			else {
				cout << MyQueue[front] << "\n";
				MyQueue[front] = 0;
				front++;
			}
		}
		//size 명령어
		if (Cmd == "size") {
			//back - front = 남아있는 정수의 수
			cout << back - front << "\n";
		}
		if (Cmd == "empty") {
			if (back == 0 || front == back) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		///front 명령어
		if (Cmd == "front") {
			if (back == 0 || front == back) {
				cout << -1 << "\n";
			}
			else {
				cout << MyQueue[front] << "\n";
			}
		}
		//back 명령어
		if (Cmd == "back") {
			if (back == 0 || front == back) {
				cout << -1 << "\n";
			}
			else {
				cout << MyQueue[back -1] << "\n";
			}
		}
	}
	delete[] MyQueue;
	return 0;
}