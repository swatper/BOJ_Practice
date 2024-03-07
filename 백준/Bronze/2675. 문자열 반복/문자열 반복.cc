#include <iostream>
using namespace std;

int main() {
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		int R;
		string Word;
		cin >> R >> Word;
		for (int a = 0; a < Word.length(); a++) {
			for (int b = 0; b < R; b++) {
				cout << Word[a];
			}
		}
		cout << "\n";
	}
	return 0;
}