#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	double NumA, NumB;
	cin >> NumA>> NumB;
	//소수점 자리 고정
	cout << fixed;
	//유효 숫자 9
	cout.precision(9);
	cout << NumA / NumB << "\n";
}