#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	//숫자 1은 모든 수의 약수, 어떤 수를 선택하든 무조건 지워짐
	//특성 수 N에 대해 필승 전략이 있으면? (훔치기 전략)
	//		-> 만약 선공이 필승이면? A는 다른 숫자를 지워 선공 유지
	//		-> 만약 후공이 필승이면? A는 1만 지워 후공을 유지
	//=> num이 1 초과인 경우 무조건 A가 유리
	if (num == 1)
		cout << 'B' << '\n';
	else
		cout << 'A' << '\n';

	return 0;
}