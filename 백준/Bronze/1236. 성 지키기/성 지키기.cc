#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char Castle[50][50];
	int Row, Colums, RowGuards = 0, ColumGuards = 0;;
	cin >> Row >> Colums;
	//각 층별로 배치 상황 입력 받기
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Colums; j++) {
			cin >> Castle[i][j];
		}
	}
	//행 기준으로 필요한 경호원 수 구하기
	for (int i = 0; i < Row; i++) {
		bool isGaurdNeed = true;
		//행에 경호원이 배치되어 있는지 확인
		for (int j = 0; j < Colums; j++) {
			if (Castle[i][j] == 'X') {
				isGaurdNeed = false;
				break;
			}
		}
		if (isGaurdNeed) {
			RowGuards++;
		}
	}
	
	//열 기준으로 필요한 경호원 수 구하기
	for (int i = 0; i < Colums; i++) {
		bool isGaurdNeed = true;
		//행에 경호원이 배치되어 있는지 확인
		for (int j = 0; j < Row; j++) {
			if (Castle[j][i] == 'X') {
				isGaurdNeed = false;
				break;
			}
		}
		if (isGaurdNeed) {
			ColumGuards++;
		}
	}

	//필요한 경호원 수 구하기
	int NeedGaurds = RowGuards > ColumGuards ? RowGuards : ColumGuards;
	cout << NeedGaurds << "\n";
	return 0;
}