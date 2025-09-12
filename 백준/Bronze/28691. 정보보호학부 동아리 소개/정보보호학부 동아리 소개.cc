#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	char club;
	cin >> club;
	if (club == 'M') {
		cout << "MatKor \n";
	}
	else if (club == 'W') {
		cout << "WiCys \n";
	}
	else if (club == 'C') {
		cout << "CyKor \n";
	}
	else if (club == 'A') {
		cout << "AlKor \n";
	}
	else if (club == '$') {
		cout << "$clear\n";
	}
	return 0;
}
