#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		//두 수의 범위의 합이 최대 20억 최서 -20억이라 int로 감당 가능
		int NumA, NumB;
		cin >> NumA >> NumB;
		cout << NumA + NumB << "\n";
	}
	return 0;
}    