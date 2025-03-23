#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Row, Column;
	cin >> Row >> Column;
	for (int i = 0; i < Row; i++){
		for (int i = 0; i < Column; i++)
			cout << '*';
		cout << "\n";
	}
	return 0;
}

