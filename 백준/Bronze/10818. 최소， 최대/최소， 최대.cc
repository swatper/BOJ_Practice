#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Max = -1000000, Min = 1000000, Nums, Num;
	cin >> Nums;
	for (int i = 0; i < Nums; i++) {
		cin >> Num;
		if (Min > Num) {
			Min = Num;
		}
		if (Max < Num) {
			Max = Num;
		}
	}
	cout << Min << "\n" << Max << "\n";
}