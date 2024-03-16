#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N , Total = 0;
	string Nums;
	cin >> N >> Nums;
	for (int i = 0; i < Nums.size(); i++) {
		Total += Nums[i]%48;
	}
	cout << Total << "\n";
	return 0;
}