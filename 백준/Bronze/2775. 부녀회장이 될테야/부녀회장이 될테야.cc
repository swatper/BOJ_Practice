#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc, Floor, Num;
	int Apt[15][15]; //2차원 배열 생성
	for (int i = 1; i < 15; i++) {
		Apt[0][i] = i; //0번째 층에 있는 사람들 수 입력
	}
	for (int i = 1; i < 15; i++) {
		Apt[i][1] = 1; //각 층에 1호에 있는 사람 수(1명) 입력 
	}
	//아파트에 모든 호수에 있는 사람 수 구하기
	for (int a = 1; a < 15; a++) {
		for (int b = 2; b < 15; b++) {
			//a층b호에 있는 사람들 수 = 옆집(a층b-1호) 사람 수 + 아래층(a-1층b호) 사람 수 
			Apt[a][b] = Apt[a][b-1] + Apt[a-1][b];
		}
	}
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		cin >> Floor >> Num;
		cout << Apt[Floor][Num] << "\n";
	}
	return 0;
}