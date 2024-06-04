#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NumA, NumB;
	int ProcResult[4] = { 0, };
	cin >> NumA >> NumB;
	//3위치 계산 (NumA와 NumB의 1의자리 곱)
	ProcResult[0] = NumA * (NumB % 10);
	//4위치 계산 (NumA와 NumB의 10의자리 곱)
	ProcResult[1] = NumA * (NumB/ 10 % 10);
	//5위치 계산 (NumA와 NumB의 100의자리 곱)
	ProcResult[2] = NumA * (NumB / 100);
	//6위치 계산 (합)
	ProcResult[3] = ProcResult[0] + ProcResult[1] * 10 + ProcResult[2] * 100;
	//결과 출력
	for (int i = 0; i < 4; i++){
		cout << ProcResult[i] << "\n";
	}
	return 0;
}