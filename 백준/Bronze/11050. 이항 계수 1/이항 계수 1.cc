#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int A, B;
	cin >> A >> B;
	//이항계수 값 저장 (다이나믹 프로그래밍)
	vector<vector<int>> DP(A + 1, vector<int>(B + 1, 0));

	for (int i = 1; i <= A; i++){
		for (int j = 0; j <= B; j++)
		{
			if (j == 0 || i == j)
				DP[i][j] = 1;
			else
				DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
		}
	}

	cout << DP[A][B] << "\n";
	return 0;
}
