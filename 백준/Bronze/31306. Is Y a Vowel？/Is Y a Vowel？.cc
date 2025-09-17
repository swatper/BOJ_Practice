#include <iostream>
using namespace std;

void CheckVowel(string target, char vowels[], int* a, int* b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	int vowelWithoutY = 0, vowelWithY = 0;
	string word;
	cin >> word;
	CheckVowel(word, vowels,&vowelWithoutY, &vowelWithY);
	cout << vowelWithoutY << ' ' << vowelWithY << "\n";
	return 0;
}

void CheckVowel(string target, char vowels[], int* a, int* b) {
	for (int i = 0; i < target.length(); i++){
		for (int j = 0; j < 5; j++){
			if (target[i] == vowels[j]) {
				(*a)++;
				(*b)++;
				break;
			}
		}
		if (target[i] == 'y') {
			(*b)++;
		}
	}
}
