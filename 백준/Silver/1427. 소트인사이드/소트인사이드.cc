#include <iostream>
#include <algorithm> //정렬 함수를 쓰기위한 추가
using namespace std;

bool NumCompair(char a , char b) {
	return a > b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Num;
	int Alpha[10] = { 0, };//모두 0으로 초기화
	cin >> Num;
	/*//방법 1: srot()알고리즘 사용
	//시작주소, 끝주소, 조건
	sort(Num.begin(), Num.end(), NumCompair);
	cout << Num + "\n";*/
	//방법 2: 배열 사용하기
	for (int i = 0; i < Num.size(); i++) {
		//각 숫자에 해당하는 인덱스 값 증가
		Alpha[Num[i] - '0']++; 
	}
	//인덱스의 뒷부분부터 증가한 숫자만큼 출력
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < Alpha[i]; j++) {
			cout << i ;
		}
	}
	return 0;
}
