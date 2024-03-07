#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, X, N;
	cin >> A >> X;
	for (int i = 0; i < A; i++) {
		cin >> N;
		if (X > N) {
			cout << N << "\n";
		}
	}
	return 0;
}