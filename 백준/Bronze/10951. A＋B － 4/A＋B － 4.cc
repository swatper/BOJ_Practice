#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {//무한 반복
		int a  = -1;
		int b  = -1;
		cin >> a >> b;

		//값을 입력 받았는지 확인
		if (a < 0 && b < 0) {
			break;
		}
		cout << a + b << "\n";
	}
	return 0;
}