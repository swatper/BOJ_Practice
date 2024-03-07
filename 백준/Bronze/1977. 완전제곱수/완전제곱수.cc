#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int M, N, Min_num, total;
	 Min_num = 0;
	total = 0;
	cin >> M >> N;
	//배열을 0으로 초기화
	bool First = false;
	for (int i = 1; i <= 100; i++ ) {
		if (i * i >= M && i * i <= N) {
			total += i * i;
			if (!First) {
				Min_num = i * i;
				First = true;
			}
		}
	}
	if (total == 0) {
		cout << "-1" << "\n";
	}
	else {
		cout << total << "\n";
		cout << Min_num << "\n";
	}
	return 0;
}