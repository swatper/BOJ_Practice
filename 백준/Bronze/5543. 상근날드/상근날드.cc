#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Bugers;
	int Drinks;
	int CheapestBuger = 3000, CheapestDrink = 3000;
	for (int i = 0; i < 3; i++) {
		cin >> Bugers;
		//삼항연산 조건식 ? 참일때의 값 : 거짓일때의 값
		CheapestBuger = Bugers < CheapestBuger ? Bugers : CheapestBuger;
	}
	for (int i = 0; i < 2; i++) {
		cin >> Drinks;
		//삼항연산 조건식 ? 참일때의 값 : 거짓일때의 값
		CheapestDrink = Drinks < CheapestDrink ? Drinks : CheapestDrink;
	}
	cout << CheapestBuger + CheapestDrink - 50<< "\n";
	return 0;
}