#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int month, day;
	cin >> month >> day;
	if (month < 2)
	{
		cout << "Before\n";
	}
	else if (month > 2) {
		cout << "After\n";
	}
	else {
		if (day < 18) {
			cout << "Before\n";
		}
		else if (day > 18){
			cout << "After\n";
		}
		else {
			cout << "Special\n";
		}
	}
	return 0;
}