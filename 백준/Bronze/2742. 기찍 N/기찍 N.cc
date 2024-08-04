#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = N; i >= 1; i--){
		cout << i << "\n";
	}
	return 0;
}