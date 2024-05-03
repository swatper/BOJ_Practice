#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Word;
	cin >> Word;
	int AddChar = 0, Backpos = Word.size();
	//팰린드롬 만들기(중간에 문자를 추가해서 만들기)
	while (true) {
		//투 포인터 사용
		int Front = 0;
		int Back = Word.size() - 1;
		//문자 확인
		bool IsPalindrome = true;
		while (Front <= Back){
			//팰린드롬 확인
			if (Word[Front] != Word[Back]) {
				IsPalindrome = false;
				break;
			}
			else{
				Front++;
				Back--;
			}
		}
		if (IsPalindrome){
			break;
		}
		else {
			//팰린드롬이 아니므로, 문자를 문자열 뒤에 추가
			Word.insert(Word.begin() + Backpos, Word[AddChar]);
			AddChar++;
		}
		//cout << Word << "\n"; //단어 상태 확인용 코드
	}
	cout << Word.size() << "\n";
	return 0;
}