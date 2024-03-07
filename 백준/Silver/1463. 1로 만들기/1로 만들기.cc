#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int Array[1000001] = {};
	Array[1] = 0;
	Array[2] = 1;
	Array[3] = 1;

	//연산을 시도한 횟수
	int Count_Oper = 0;

	for (int i = 2; i <= N; i++) {
		if (i * 2<= N) {
			if (Array[i * 2] != 0) {
				Array[i * 2] = Array[i * 2] > Array[i] + 1 ? Array[i] + 1 : Array[i * 2];
			}
			else
				Array[i * 2] = Array[i] + 1;
		}

		if (i * 3 <= N) {
			if (Array[i * 3] != 0) {
				Array[i * 3] = Array[i * 3] > Array[i] + 1 ? Array[i] + 1 : Array[i * 3];
			}
			else
				Array[i * 3] = Array[i] + 1;
		}

		if (Array[i + 1] != 0) {
			Array[i + 1] = Array[i + 1] > Array[i] + 1? Array[i] + 1: Array[i + 1];
		}
		else
			Array[i + 1] = Array[i] + 1;

	}
	cout << Array[N] << "\n";
	return 0;
}