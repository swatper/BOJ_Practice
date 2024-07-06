#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Stones[1001];
	Stones[1] = "CY\n";
	Stones[2] = "SK\n";
	Stones[3] = "CY\n";
	for (int i = 4; i <= 1000; i++){
		//돌이 홀수개로 남으면 상근이(SK)가 승리함
		if (i % 2 == 0) {
			Stones[i] = "SK\n";
		}
		//돌이 홀수개로 남으면 창영이(CY)가 승리하고
		else {
			Stones[i] = "CY\n";
		}
	}
	int Stone;
	cin >> Stone;
	cout << Stones[Stone];
	return 0;
}