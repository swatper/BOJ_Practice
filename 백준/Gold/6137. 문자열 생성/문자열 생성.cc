#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string SWord, ResultWord = "";
	int WordLength;
	cin >> WordLength;
	for (int i = 0; i < WordLength; i++) {
		string Temp;
		cin >> Temp;
		SWord += Temp;
	}
	int Front = 0, Back = SWord.length() - 1;
	while (Front <= Back){
		//문자열의 앞 뒤 문자 중 어느 문자가 더 빠른지(아스키 값 비교)확인
		if (SWord[Front] < SWord[Back]) {
			ResultWord += SWord[Front];
			Front++;
		}

		else if (SWord[Front] > SWord[Back]) {
			ResultWord += SWord[Back];
			Back--;
		}

		//두 문자가 서로 같은 경우, 안쪽(?)에 있는 문자 비교
		else {
			//안쪽의 문자가 모두 같은 경우를 확인하기 위한 bool 변수
			bool isDiff = false;
			int TempIndex = 1;
			while (Front + TempIndex <= Back - TempIndex) {
				
				if (SWord[Front + TempIndex] < SWord[Back - TempIndex]) {
					ResultWord += SWord[Front];
					Front++;
					isDiff = true;
					break;
				}
				
				else if (SWord[Front + TempIndex] > SWord[Back - TempIndex]) {
					ResultWord += SWord[Back];
					Back--;
					isDiff = true;
					break;
				}
				else {
					TempIndex++;
				}
			}
			//만약 안쪽에 있는 모든 문자가 같은 경우 양쪽의 문자를 모두 저장
			if (!isDiff) {
				ResultWord+= SWord[Front];
				Front++;
			}
		}
	}
	//80문자씩 끊어서 출력
	for (int i = 0; i < ResultWord.length();) {
		cout << ResultWord[i];
		i++;
		if (i % 80 == 0) {
			cout << "\n";
		}
	}
	return 0;
}