#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Soonsil, Korea, Hanyang;
	cin >> Soonsil >> Korea >> Hanyang;

	if (Soonsil + Korea + Hanyang >= 100)
	{
		cout << "OK\n";
	}
	else {
		if (Korea > Soonsil&& Hanyang > Soonsil) {
			cout << "Soongsil\n";
		}
		else if (Soonsil > Korea && Hanyang > Korea) {
			cout << "Korea\n";
		}
		else if (Soonsil > Hanyang && Korea > Hanyang) {
			cout << "Hanyang\n";
		}
	}
	return 0;
}