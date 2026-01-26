#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<char> &word, vector<char> &list, int length, int index);		//깊이 우선 탐색
bool CheckPossible(vector<char>& target); //자음/모음 개수 확인

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int length, chars;
	cin >> length >> chars;
	vector<char> charList(chars);
	for (int i = 0; i < chars; i++){
		cin >> charList[i];
	}
	vector<char> password;
	sort(charList.begin(), charList.end());
	DFS(password, charList, length , 0);
	return 0;
}


void DFS(vector<char>& word, vector<char>& list, int length, int index) {
	//암호 사용 여부 확인 및 출력
	if (word.size() == length) {
		if (CheckPossible(word)) {
			for (int i = 0; i < word.size(); i++)
				cout << word[i];
			cout << '\n';
		}
		return;
	}
	//탐색 시작
	for (int i = index; i < list.size(); i++){
		word.push_back(list[i]);
		//재귀
		DFS(word, list, length, i + 1);
		//이동
		word.pop_back();
	}

}

bool CheckPossible(vector<char>& target) {
	int consonant = 0, vowel = 0;
	for (int i = 0; i < target.size(); i++){
		if (target[i] == 'a' || target[i] == 'e' || target[i] == 'i'
			|| target[i] == 'o' || target[i] == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}
	}
	if (vowel < 1  || consonant < 2)
		return false;

	return true;
}