#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int F_n2 = 0;
	int F_n1 = 1;
	int F_n = 0;
	int n;
	cin >> n;
	if (n < 2) {
		cout << n << "\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			F_n = F_n1 + F_n2;
			F_n2 = F_n1;
			F_n1 = F_n;
		}
		cout << F_n << "\n";
	}
}