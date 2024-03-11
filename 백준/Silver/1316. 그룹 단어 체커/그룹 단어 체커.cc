#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Words, Result;
	cin >> Words;
	Result = Words;
	string Word;
	for (int i = 0; i < Words; i++) {
		bool Alpha[26] = { false };
		cin >> Word;

		Alpha[(int)Word[0] - 97] = true;
		for (int j = 1; j < Word.size(); j++) {
			if (Alpha[Word[j] - 97] == false) {
				Alpha[Word[j] - 97] = true;
			}
			else if (Alpha[Word[j] - 97] == true && Word[j - 1] != Word[j]) {
				Result--;
				break;
			}
		}
	}
	cout << Result << "\n";
	return 0;
}