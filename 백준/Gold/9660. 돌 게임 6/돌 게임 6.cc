#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned long stones;
	cin >> stones;

	//님(Nim)게임처럼 수학으로 규칙 찾아서 풀기
	//상근이 차례일 때, 돌이 0개거나 2개면 창영이가 승리
	//반대로 1개, 3개, 4개, 5개, 6개 상근이가 승리
	//돌이 7개 이상부터는 앞의 0개~6개의 시라니오가 반복되서 나타남
	//-> 7로 나누었을 때, 돌이 0개거나 2개 남아있으면 창영이가 승리
	if (stones % 7 == 0 || stones % 7 == 2)
		cout << "CY\n";
	else
		cout << "SK\n";

	return 0;
}