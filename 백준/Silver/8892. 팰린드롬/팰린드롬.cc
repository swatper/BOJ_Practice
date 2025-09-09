#include <iostream>
using namespace std;

bool CheckPalindrome(string word);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		int words, count = 0;
		string hasPalindrome = "0\n";
		cin >> words;
		string* wordsList = new string[words]; //동적 할당
		//입력
		for (int j = 0; j < words; j++) {
			cin >> wordsList[j];
		}
		//조합 및 확인
		for (int j = 0; j < words; j++) {
			for (int k = 0; k < words; k++) {
				if (j == k)
					continue;
				if (CheckPalindrome(wordsList[j] + wordsList[k])) 
					hasPalindrome = wordsList[j] + wordsList[k];
			}
		}
		cout << hasPalindrome << "\n";
		delete[] wordsList; //반환
	}
	return 0;
}

//투 포인터를 이용하여 탐색
bool CheckPalindrome(string word) {
	int front = 0, back = word.length() - 1;
	bool isPalindrome = true;
	//탐색 시작
	while (front <= back) {
		if (word[front] != word[back]) {
			isPalindrome = false;
			break;
		}
		front++;
		back--;
	}
	return isPalindrome;
}