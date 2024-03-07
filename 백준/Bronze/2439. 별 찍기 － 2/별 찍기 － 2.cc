#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int a = N; a > i; a--) {
			cout << " ";
		}
		for (int b = 1; b <= i; b++) {
			cout << "*";
		}
		cout << endl;
	}
}