#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int bankA, bankB, Chicken, Total;
	cin >> bankA >> bankB >> Chicken;
	Total = bankA + bankB;
	if (Total < Chicken * 2){
		cout << Total;
	}
	else {
		cout << Total - (Chicken * 2);
	}
	cout << "\n";
	return 0;
}