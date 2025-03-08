#include <iostream>
#define MAX 1001
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int stones;
	cin >> stones;
	//다이나믹 프로그래밍으로 풀기
	bool* DP = new bool[MAX];
	DP[0] = false;
	DP[1] = true;
	DP[2] = false;
	DP[3] = true;
	DP[4] = true;

	//돌이 5개 이상부터 n-1개, n-3개, n-4개 판에서
	//상근이가 진 판이 한 번이라도 있으면(남은 돌이 있었다면)
	//n개 일때 마지막 차례는 상근이이므로, 나머지 돌을 가져감
	//-> 상근이 승리
	//반대로 n-1개, n-3개, n-4개 판에서 상근이가 모두 이기면
	//n개판의 마지막 차례일때 무조건 돌이 남기 때문에, 상근이는 패배
	for (int i = 5; i < MAX; i++)
	{
		if (!DP[i - 1] || !DP[i - 3] || !DP[i - 4])
			DP[i] = true;
		else
			DP[i] = false;
	}

	if (DP[stones])
		cout << "SK\n";
	else
		cout << "CY\n";

	delete[] DP;
	return 0;
}