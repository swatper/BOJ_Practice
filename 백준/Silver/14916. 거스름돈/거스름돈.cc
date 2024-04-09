#include <iostream>
#define MAX 100001
using namespace std;

int MinCoins[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Money;
	//방법 1. 다이나믹 프로그래밍으로 풀기
	MinCoins[1] = -1;
	MinCoins[2] = 1;
	MinCoins[3] = -1;
	MinCoins[4] = 2;
	MinCoins[5] = 1;
	MinCoins[6] = 3;
	MinCoins[7] = 2;
	MinCoins[8] = 4;
	MinCoins[9] = 3;
	MinCoins[10] = 2;
	for (int i = 11; i < MAX; i++) {
		MinCoins[i] = MinCoins[i - 5] + 1;
	}
	cin >> Money;
	cout << MinCoins[Money] << "\n";
	return 0;
}