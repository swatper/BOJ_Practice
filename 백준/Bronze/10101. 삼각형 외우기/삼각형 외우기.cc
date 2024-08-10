#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B, C;
	cin >> A >> B >> C;
	if (A ==60 && B == 60 && C == 60)
	{
		cout << "Equilateral\n";
	}
	else if (A + B + C == 180) {
		if (A == B || B == C || C == A)
		{
			cout << "Isosceles\n";
		}
		else {
			cout << "Scalene\n";
		}
	}
	else {
		cout << "Error\n";
	}
	return 0;
}