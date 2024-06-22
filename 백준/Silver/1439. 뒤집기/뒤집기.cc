#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	//문자가 달라지는 횟수를 저장할 변수
	int Count = 0;
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] != S[i + 1]){
			Count++;
		}	
	}
	//문자가 달라지는 전체 횟수를 절반으로 나누면
	//최소 횟수를 구할 수 있음
	cout << (Count + 1) / 2 << "\n";
	return 0;
}    