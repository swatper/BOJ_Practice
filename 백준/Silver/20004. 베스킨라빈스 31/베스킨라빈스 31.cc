/*"생활속의수리"때 님(Nim)게임 구현*/
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	//먼저 30을 부르는 사람이 승리
	// -> 매번 ((최대로 부를 수 있는 개수) + 1)의 배수로 부르면 무조건 승리 가능
	// -> (최대로 부를 수 있는 개수) + 1)수가 30의 약수면 무조건 승리
	for (int i = 1; i <= N; i++)
	{
		if(30 % (i + 1) == 0)
			cout << i << "\n";
	}
}