#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int R1, R2,S;
	cin >> R1 >> S;
	R2 = (S * 2) - R1;
	cout << R2 << "\n";
	return 0;
}