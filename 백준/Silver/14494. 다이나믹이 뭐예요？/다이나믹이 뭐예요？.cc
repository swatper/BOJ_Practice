#include <iostream>
#define MOD  1000000007 //10^9+7
using namespace std;

unsigned int DP[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	//초기화
	for (int i = 1; i < 1001; i++){
		DP[1][i] = 1;
		DP[i][1] = 1;
	}

	//나머지 값 구하기
	for (int i = 2; i < 1001; i++){
		for (int j = 2; j < 1001; j++) {
			//특정 위치로 갈 수 있는 경우의 수는
			//위에서 내려오거나
			//왼쪽에서 오거나
			//왼쪽 위 대각선에서 내려올 수 있으므로
			//해당 위치들의 경우의 수를 모두 더하면 됨
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1] + DP[i - 1][j - 1]) % MOD;
		}
	}

	cout << DP[N][M] << "\n";
	return 0;
}