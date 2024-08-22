#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string S, Result = "";
	int Ones = 0, Zeros = 0, Count = 0;
	cin >> S;
	//문자의 특정 위치 문자의 삭제 여부를 저장할 배열
	bool *Index = new bool[S.size()]; 

	//1과 0의 갯수 세개
	for (int i = 0; i < S.size(); i++){
		Index[i] = false; //초기화
		if (S[i] == '1'){
			Ones++;
		}
		else {
			Zeros++;
		}
	}
	
	//뒤에서 지울 0의 index 확인
	for (int i = S.size() - 1; i >= 0 ; i--){
		if (Count == Zeros / 2) {
			break;
		}
		if (S[i] == '0') {
			Count++;
			Index[i] = true;
		}
	}
	
	//앞에서 지울 1의 index 확인
	Count = 0;
	for (int i = 0; i < S.size() ; i++) {
		if (Count == Ones / 2) {
			break;
		}
		if (S[i] == '1') {
			Count++;
			Index[i] = true;
		}
	}

	for (int i = 0; i < S.size(); i++){
		if (!Index[i]) {
			Result += S[i];
		}
	}

	cout << Result + "\n";
	return 0;
}