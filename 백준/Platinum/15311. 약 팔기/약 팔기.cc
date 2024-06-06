#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//일단 동규가 요구하는 약의 갯수는 100만개
	//알약 봉투는 총 2000개
	//1000개짜리 봉투 1000개를 준비해서 더하면, 1000단위 ~ 100만을 표현하고
	//1개짜리 봉투 999개를 준비해서 더하면, 1~999를 표현하면
	//1~100만까지의 수를 모두 표현할 수 있음
	//총 필요한 봉투: 1999개
	cout << "1999\n";
	for (int i = 1; i < 1000; i++){
		cout << 1 << " ";
	}
	cout << " ";
	for (int i = 1; i <= 1000; i++){
		cout << 1000 << " ";
	}
	cout << "\n";
	//실버5 1402 문제와 비슷한 문제인 듯
	return 0;
}