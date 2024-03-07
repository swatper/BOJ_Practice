#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);//cin과 cout을 묶어줌 -> 입출력을 번갈아 할 경우 꼭 필요
	ios_base::sync_with_stdio(false); //C와 C++의 버퍼를 분리
	int a, b;
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
}