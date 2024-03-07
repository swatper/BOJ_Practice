#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //C 와 C++을 분리 -> 속도가 빨라짐
	cin.tie(NULL); //cin 과 cout을 풀어줌 ->버퍼를 지우는 과정 생략 -> 속도가 빨라짐

	int check = 1;	//팰린드롬인지 아닌지 확인하는 변수
	string Word;	//문자열을 입력받을 변수
	cin >> Word;	//문자열 입력받기

	//팰린드롬인지 아닌지 확인하는 과정
	for (int i = 0; i <= Word.length() / 2; i++) {		//문자열 전체길이의 절반만 반복
		if (Word[i] != Word[Word.length() - i - 1]) {	//문자열의 맨 앞과 뒤의 문자를 비교
			check = 0;
			break;
		}
	}
	cout << check << "\n";
	return 0;
}