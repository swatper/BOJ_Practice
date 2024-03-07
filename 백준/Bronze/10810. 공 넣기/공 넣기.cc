#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int* bascket = new int[N + 1];
	for (int i = 1; i <= N ;i++) {
		bascket[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b;j++) {
			bascket[j] = c;
		}
	}
	for (int i = 1; i <= N ;i++) {
		cout << bascket[i] << " ";
	}
	cout << "\n";
	return 0;
}