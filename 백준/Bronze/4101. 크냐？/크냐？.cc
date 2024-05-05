#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Num1, Num2;
	while (true){
		cin >> Num1 >> Num2;
		if (Num1 == 0 && Num2 == 0) {
			break;
		}
		else {
			if (Num1 > Num2){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
	}
	return 0;
}