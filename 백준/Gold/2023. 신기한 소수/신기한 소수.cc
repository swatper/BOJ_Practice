#include <iostream>
using namespace std;

void DFS(int curNum, int curDigit, int length);
bool CheckPrime(int target);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int primeNums[4] = { 2, 3, 5, 7 };
	int N;
	cin >> N;
	for (int i = 0; i < 4; i++){
		DFS(primeNums[i], 1,N);
	}
	return 0;
}

//깊이 우선 탐색으로 확인(재귀)
void DFS(int curNum, int curDigit,int length) {
	if (curDigit == length) {
		cout << curNum << '\n';
		return;
	}
	for (int i = 1; i < 10; i++) {
		int nxtNum = curNum * 10 + i;
		if (CheckPrime(nxtNum)) {
			DFS(nxtNum, curDigit + 1, length);
		}
	}
}

//소수 확인
bool CheckPrime(int target){
	bool isPrime = true;
	for (int i = 2; i  * i<= target; i++){
		if (target % i == 0) {
			isPrime = false;
			break;
		}
	}
	return isPrime;
}