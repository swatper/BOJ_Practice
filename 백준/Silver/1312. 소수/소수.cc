#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//입력받은 값을 저장할 변수
	int a, b, c;
	//계산하는데 사용할 변수
	int x;
	//값 입력받기
	cin >> a >> b >> c;

	//a와 b를 나누었을 때 소수점 아래 값들은 몫이라고 생각
	//-> 각 자리마다 10을 곱하고 나눈 몫을 이용
	for (int i = 1; i <= c; i++) {
		//a 와 b를 나눈 나머지를 이용(몫은 소수점이 아니므로 필요없음)
		a %= b;
		//나머지는 소수점으로 표현되므로 표현하기전에 10을 곱함
		a *= 10;
		//다시 a 와 b를 나누어 몫을 구함
		x = a / b;
	}
	cout << x << "\n";
}