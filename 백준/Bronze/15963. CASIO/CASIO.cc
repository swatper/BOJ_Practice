#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long BatteryA, BatteryB;
	cin >> BatteryA >> BatteryB;
	cout << (BatteryA == BatteryB ? 1 : 0);
	return 0;
}

