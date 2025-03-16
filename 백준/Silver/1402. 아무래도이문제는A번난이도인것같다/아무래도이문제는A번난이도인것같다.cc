#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		int NumA, NumB;
		cin >> NumA >> NumB;
		//NumA를 a1*a2*a3..로 인수분해 하였을 때
		//1과 -1을 적절히 사용하여 표현하면
		//얼마든지 NumB를 만들 수 있음
		//5: 5 * (-1) * (-1) *(-1) * (-1) -> 1
		//5 * (-1) * (-1) *(-1) * (-1) -> 2   
		//5: 5 * (-1) * (-1)-> 3
		//5: 5 * (-1) * (-1) * (1) -> 4
		//5: 5 * (-1) * (-1) * (1)  * (1) -> 5
		//5: 5 * (1) -> 6
		//그러므로 모든 숫자를 표현할 수 있음
		cout << "yes\n";
	}
	return 0;
}