#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B;
	int a, b, bigger;
	cin >> A >> B;
	//입력받은 수의 1의자릿수는 10으로 나눈 나머지로 100의자리수로 바꿈
	//10의 자릿수는 10의 몫에 10을 나눈 나머지를 구할 수 있음
	//100의 자릿수는 100으로 나눈 몫으로 1의자리수로 바꿈
	a = 100 * (A % 10) + ((A / 10) % 10) * 10 +(A / 100);
	b = 100 * (B % 10) + ((B / 10) % 10) * 10 +(B / 100);
	//삼항연산
	bigger = a > b ? a : b;
	cout << bigger << "\n";
	return 0;
}