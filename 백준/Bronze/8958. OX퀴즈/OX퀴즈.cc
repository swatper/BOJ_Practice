#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	string Word;
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		cin >> Word;
		int Total = 0, Count = 1;
		for (int j = 0; j < Word.length(); j++) {
			if (Word[j] == 'O') {
				Total += Count;
				Count += 1;
			}
			else {
				Count = 1;
			}
		}
		cout << Total << "\n";
	}
	return 0;
}