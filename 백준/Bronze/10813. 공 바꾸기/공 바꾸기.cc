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
		bascket[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b, tmp;
		cin >> a >> b;
		tmp = bascket[a];
		bascket[a] = bascket[b];
		bascket[b] = tmp;
	}
	for (int i = 1; i <= N ;i++) {
		cout << bascket[i] << " ";
	}
	cout << "\n";
	return 0;
}