#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, Card, Num = 0;
	cin >> N >> M;
	int* CardsArray = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> CardsArray[i];
	}
	for (int a = 0; a < N - 2; a++) {
		for (int b = a + 1; b < N - 1; b++) {
			for (int c = b + 1; c < N; c++) {
				int Total = CardsArray[a] + CardsArray[b] + CardsArray[c];
				if (Total > Num && Total <= M) {
					Num = Total;
				}
			}
		}
	}
	cout << Num << "\n";
	delete[] CardsArray;
	return 0;
}