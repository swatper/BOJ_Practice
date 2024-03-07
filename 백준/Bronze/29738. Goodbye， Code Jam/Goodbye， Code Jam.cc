#include <iostream>
#include <string>
using namespace std;

string Round(int r) {
	if (r <= 25) {
		return "World Finals";
	}
	if (r <= 1000) {
		return "Round 3";
	}
	if (r <= 4500) {
		return "Round 2";
	}
	else {
		return "Round 1";
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++) {
		int rank;
		cin >> rank;
		cout << "Case #" << i << ": " << Round(rank) << "\n";
	}
	return 0;
} 