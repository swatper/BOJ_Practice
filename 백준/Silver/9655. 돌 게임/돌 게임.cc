#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int stones;
	cin >> stones;
	//돌 1: 상근
	//돌 2: 창영
	//돌 3: 상근
	//돌 4: 창영 .....
	//돌의 개수가 홀수면 상근이가 승리하고
	//돌의 개수가 짝수면 창영이가 승리
	if (stones % 2){
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
	}
	return 0;
}