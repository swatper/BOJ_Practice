#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M = 0;
	cin >> N;

	for (int i = N - 1; i > 0; i--){
		int target = i;
		int tmp = i;
		//각 자리수의 합 계산
		while (tmp > 0) {
			target += tmp % 10;
			tmp /= 10;
		}
		//생성자인지 확인
		if (target == N)
			M = i;
	}
	cout << M << "\n";
	return 0;
}