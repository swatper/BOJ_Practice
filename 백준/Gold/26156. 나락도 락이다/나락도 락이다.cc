#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	string word;
	cin >> n >> word;

	//각 문자별 부분 문자열 계산 (동적할당)
	int *DP = new int[n + 1];
	DP[0] = 1;
	for (int i = 1; i <= n; i++) 
		DP[i] = (DP[i - 1] * 2) % MOD;

	//앞에서 부터 찾기
	int cntR = 0;			//"R" 의 개수
	int cntRO = 0;		//"RO"의 개수
	int cntROC = 0;	// "ROC"의 개수
	int cntROCK = 0;	// "ROC"의 개수

	//ROCK 문자열의 앞부터 필터링
	for (int i = 0; i < n; i++){
		if (word[i] == 'R')
			cntR = (cntR + DP[i]) % MOD;
		else if (word[i] == 'O')
			cntRO = (cntRO + cntR) % MOD;
		else if (word[i] == 'C')
			cntROC = (cntROC + cntRO) % MOD;
		else if (word[i] == 'K')
			cntROCK = (cntROCK + cntROC) % MOD;
	}
	cout << cntROCK << '\n';
	delete[] DP;
	return 0;
}