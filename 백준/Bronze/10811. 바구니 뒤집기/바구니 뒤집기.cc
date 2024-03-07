#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int* bascket = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		bascket[i] = i;
	}
	//바구니 역순
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j <= (b - a) / 2; j++) {
			int tmp;
			tmp = bascket[a + j];
			bascket[a + j] = bascket[b - j];
			bascket[b - j] = tmp;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << bascket[i] << " ";
	}
	cout << "\n";
	return 0;
}