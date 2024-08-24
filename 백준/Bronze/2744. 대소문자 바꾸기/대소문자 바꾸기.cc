#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Word;
	cin >> Word;
	for (int i = 0; i < Word.size(); i++){
		//대문자면
		if (Word[i] >= 'A' && Word[i] <= 'Z') {
			Word[i] += 32;
		}
		//소문자면
		else {
			Word[i] -= 32;
		}
	}
	cout << Word + "\n";
	return 0;
}