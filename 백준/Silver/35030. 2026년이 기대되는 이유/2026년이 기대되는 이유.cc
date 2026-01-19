#include <iostream>
#define MAX 100001
using namespace std;

bool primeNums[MAX] = { false, };		//소수 판정 저장
int sumOfSpecial[MAX] = { 0, };			//소수 갯수 저장 (누적합)

bool CheckSpecial(int n);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc, target;
	primeNums[0] = false;
	primeNums[1] = false;
	//판정 초기화
	for (int i = 2; i < MAX; i++)
		primeNums[i] = true;
	//제곱으로 소수 판정
	for (int i = 2; i * i < MAX; i++) {
		if (primeNums[i]) {
			for (int j = i * i; j < MAX; j+= i){
				primeNums[j] = false;
			}
		}
	}
	sumOfSpecial[1] = 1;
	//누적 합 구하기
	for (int i = 2; i < MAX; i++){
		int pre = sumOfSpecial[i - 1];
		sumOfSpecial[i] = CheckSpecial(i) ? pre + 1 : pre;
	}
	cin >> tc;
	for (int i = 0; i < tc; i++){
		cin >> target;
		cout << sumOfSpecial[target] << '\n';
	}
	return 0;
}

bool CheckSpecial(int n) {
	if (!primeNums[n + 1])
		return false;

	int digit = 10;
	while (digit <= n) {
		int front = n / digit;
		int back = n % digit;

		if (front == 0)
			break;

		if (!primeNums[front * back + 1])
			return false;
		digit *= 10;
	}
	return true;
}