#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc, A, B;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		cin >> A >> B;
		cout << A + B << "\n";
	}
	return 0;
}