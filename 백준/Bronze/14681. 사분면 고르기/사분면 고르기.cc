#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int X, Y , Result = 0;

	cin >> X >> Y;
	if (X > 0) {
		if (Y > 0)
			Result = 1;
		else
			Result = 4;
	}
	else {
		if (Y > 0)
			Result = 2;
		else
			Result = 3;
	}

	cout << Result << "\n";
	return 0;
}