#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	bool isExist = true;
	int index, Max = 0;
	int Alpha[26];
	for (int i = 0; i < 26; i++) {
		Alpha[i] = 0;
	}
	string Word;
	cin >> Word;
	for (int i = 0; i < Word.length(); i++) {
		//소문자 아스키코드
		if (Word[i] >= 97) {
			Alpha[Word[i] - 97]++;
		}
		//대문자 아스키코드
		else {
			Alpha[Word[i] - 65]++;
		}
	}
	//가장 많이 사용된 알파뱃이 어러 개인지 확인
	for (int i = 0; i < 26; i++) {
		if (Max == Alpha[i]) {
			isExist = false;
		}
		else if (Max < Alpha[i]) {
			isExist = true;
			Max = Alpha[i];
			index = i;
		}
	}
	//결과 출력
	if (isExist) {
		//정수를 아스키코드 값으로 바꿔 문자로 출력
		cout << (char)(index + 65) << "\n";
	}
	else {
		cout << "?\n";
	}
	return 0;
}