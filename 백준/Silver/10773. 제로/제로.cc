#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned int Money , Total = 0;
	stack<unsigned int>Ledger;
	cin >> Money;
	for (int i = 0; i < Money; i++) {
		int Temp;
		cin >> Temp;
		if (Temp == 0) { //장부 지우기
			Ledger.pop();
		}
		else { //장부 채우기
			Ledger.push(Temp);
		}
	}
	for(int i = Ledger.size() - 1; i >= 0; i--) {
		Total += Ledger.top();
		Ledger.pop();
	}
	cout << Total << "\n";
	return 0;
}