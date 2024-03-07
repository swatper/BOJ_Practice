#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned int N;
	unsigned int result = 1;
	cin >> N;
	for (double i = 1; i <= N; i++) {
		result = result * i;
	}
	cout << result << "\n";
}