#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Array[10] = { 0, };
	int NumA, NumB, NumC;
	cin >> NumA >> NumB >> NumC;
	int Result = NumA * NumB * NumC;
	//%연산을 사용하여 각 자리 숫자의 값을 확인
	while (Result != 0) {
		int Temp = Result % 10;
		Array[Temp]++;
		//자릿수 이동
		Result = Result / 10;
	}
	for (int i = 0; i < 10; i++){
		cout << Array[i] << "\n";
	}
	return 0;
}