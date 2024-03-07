#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Tc, W, H, People;
	cin >> Tc;

	for (int i = 0; i < Tc; i++) {
		int Room_Num = 0;
		cin >> H >> W >> People;
		if (People% H == 0) {
			//나머지가 없으면 호수의 100의자리 숫자가 이되므로
			//100의자리 숫자에 높이를 곱함
			Room_Num = H * 100 + (People / H);
		}
		else {
			Room_Num = 100 * (People % H) + (People / H) + 1;
		}
		cout << Room_Num << "\n";
	}

	return 0;
}
