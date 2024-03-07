#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Total_time = 0;
	string Spells;
	cin >> Spells;
	for (int i = 0; i < Spells.length(); i++) {
		//문자열 Spells의 문자를 아스키 코드의 값과 비교하셔 계산
		if (Spells[i] >= 'A' && Spells[i] <= 'C') { //숫자 2
			Total_time += 3;
			continue;
		}
		if (Spells[i] >= 'D' && Spells[i] <= 'F') { //숫자 3
			Total_time += 4;
			continue;
		}
		if (Spells[i] >= 'G' && Spells[i] <= 'I') { //숫자 4
			Total_time += 5;
			continue;
		}
		if (Spells[i] >= 'J' && Spells[i] <= 'L') { //숫자 5
			Total_time += 6;
			continue;
		}
		if (Spells[i] >= 'M' && Spells[i] <= 'O') { //숫자 6
			Total_time += 7;
			continue;
		}
		if (Spells[i] >= 'P' && Spells[i] <= 'S') { //숫자 7
			Total_time += 8;
			continue;
		}
		if (Spells[i] >= 'T' && Spells[i] <= 'V') { //숫자 8
			Total_time += 9;
			continue;
		}
		else { //숫자 9
			Total_time += 10;
			continue;
		}
	}
	cout << Total_time << "\n";
	return 0;
}