#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int  H, M;
	cin >> H >> M;
	if (M < 45) {
		if (H == 0) {
			H = 23;
		}
		else{
			H -= 1;
		}
		M += 15;
	}
	else {
		M -= 45;
	}
	cout << H << " " << M << "\n";
	return 0;
}