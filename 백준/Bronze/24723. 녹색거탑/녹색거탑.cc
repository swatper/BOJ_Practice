#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int height, Total = 1;
	cin >> height;
	for (int i = 1; i <= height; i++){
		//각 층의 하나에 블록에서 내려오는 방법은 왼쪽 오른쪽 2가지
		//--> 경우의 수가 2배씩 증가
		Total *= 2;
	}
	cout << Total << "\n";
	return 0;
}