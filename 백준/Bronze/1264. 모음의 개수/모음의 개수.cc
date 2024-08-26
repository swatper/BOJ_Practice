#include <iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char Vowels[10] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u','U' };
	string Sentence;
	while (true) {
		int Count = 0;
		getline(cin, Sentence);
		if (Sentence == "#")
		{
			break;
		}
		for (int i = 0; i < Sentence.size(); i++){
			//모음 개수 확인
			for (int j = 0; j < 10; j++){
				if (Sentence[i] == Vowels[j]) {
					Count++;
					break;
				}

			}
			/* 비효율
			switch (Sentence[i]){
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				Count++;
				break;
			}
			*/
		}
		cout << Count << "\n";
	}
	return 0;
}