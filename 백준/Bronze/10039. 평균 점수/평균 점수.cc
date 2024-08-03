#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Score, Avg = 0;

	for (int i = 0; i < 5; i++){
		cin >> Score;

		if (Score < 40) {
			Score = 40;
		}

		Avg += Score;
	}

	Avg /= 5;

	cout << Avg<< "\n";
	return 0;
}