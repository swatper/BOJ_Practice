#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int totalcontaiers = 0;
	int containers;
	for (int i = 0; i < 6; i++){
		cin >> containers;
		totalcontaiers += containers;
	}
	cout << totalcontaiers * 5 << "\n";
	return 0;
}
