#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string word_s;
	cin >> word_s;
	int Alpa[26];
	for (int i = 0; i < 26; i++) {
		Alpa[i] = -1;
	}
	for (int i = 0; i < word_s.length();i++) {
		int tmp = 0;
		//아스키 코드로 변환하여 값을 뺀 값을 인덱스로하여 저장
		tmp = word_s[i] - 97;
		if (Alpa[tmp] == -1) {
			Alpa[tmp] = i;
		}
		//cout << tmp << " " << i << "\n";
	}
	for (int i = 0; i < 26; i++) {
		cout << Alpa[i] << " ";
	}
	cout << "\n";
	return 0;
}