#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Min, Sec, Total = 0;
	for (int i = 0; i < 4; i++) {
		int Time;
		cin >> Time;
		Total += Time;
	}
	Min = Total / 60;
	Sec = Total % 60;
	cout << Min << "\n" << Sec << "\n";
	return 0;
}