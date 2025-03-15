#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	//다이나믹 프로그래밍을 위한 2차원 배열 생성
	vector<int>DP(N + 1, 0);
	DP[1] = 1; //l
	DP[2] = 2; //ll, =

	//n=3 부터는 n-1과 n-2의 값을 더하면 구할 수 있음
		//n=3: l= , =1 , lll            -> 3
		//n=4: ll= , l=l, =ll, 1111, == -> 5
		//...
	for (int i = 3; i < N+1; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;

	cout << (DP[N]) << "\n";

	return 0;
}