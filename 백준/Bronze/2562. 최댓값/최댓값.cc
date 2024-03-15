#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Num, Highest = -1,Index = 0;
	for (int i = 1; i < 10; i++) {
		cin >> Num;
		if (Num > Highest) {
			Highest = Num;
			Index = i;
		}
	}
	cout << Highest << "\n" << Index << "\n";
	return 0;
}