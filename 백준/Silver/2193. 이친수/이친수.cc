#include <iostream>
using namespace std;

long long DP[91] = {0, 1, 1};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	// i자리 이친수의 개수는  (i - 1)자리 이친수의 개수와 (i - 2)자리 이친수의 개수를 더하면 됨
	//-> 3자리 이친수부터 모든 수는 앞에 10이 붙게 됨
	//-> 앞의 두 자리를 빼고 나머지 자리에 올 수 있는 값 들은
	//-> (i - 1)자리 이친수의 맨 앞자리를 뺀 나미저 값을 가져올 수 있음
	//-> (i - 2)자리 이친수의 값을 그대로 가져올 수 있음 
	//-> ex) 1, 10, 10?: 100 (2자리의 값 0), 101 (1자리의 값 1)
	for (int i = 3; i < 91; i++){
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N] << "\n";
	return 0;
}