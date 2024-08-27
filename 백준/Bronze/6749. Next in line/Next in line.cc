#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int yAge, mAge;
	cin >> yAge >> mAge;
	cout << mAge + (mAge - yAge) << "\n";
	return 0;
}