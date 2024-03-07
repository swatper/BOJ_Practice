#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc;i++) {
		unsigned int a, b;
		int num= 1;
		cin >> a >> b;
		//각 제곱마다 일의자리 숫자만 기억하면 됨
		for (int j = 1; j <= b; j++) {
			num = (num * a) % 10;
		}
		if (num == 0) {
			cout << 10 << "\n";
		}
		else{
			cout << num << "\n";
		}
	}
	return 0;
}