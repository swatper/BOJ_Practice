#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int Houses, Result;
	cin >> Houses;
	//2차원 배열 생성
	vector<vector<int>> DP(Houses + 1, vector<int>(3, 0));
	DP[0][0] = 0;
	DP[0][1] = 0;
	DP[0][2] = 0;
	for (int i = 1; i <= Houses; i++){
		cin >> DP[i][0] >> DP[i][1] >> DP[i][2];
		//자신의 색상을 제외한 다른 색상의 값 중
		//가장 작은 값을 더해서 저장
		DP[i][0] += DP[i - 1][1] < DP[i - 1][2] ? DP[i - 1][1] : DP[i - 1][2];
		DP[i][1] += DP[i - 1][0] < DP[i - 1][2] ? DP[i - 1][0] : DP[i - 1][2];
		DP[i][2] += DP[i - 1][0] < DP[i - 1][1] ? DP[i - 1][0] : DP[i - 1][1];
	}
	//맨 마지막의 R G B 값 중 가장 작은 값을 출력
	Result = DP[Houses][0] < DP[Houses][1] ? DP[Houses][0] : DP[Houses][1];
	Result = DP[Houses][2] < Result ? DP[Houses][2] : Result;
	cout << Result << "\n";
}    