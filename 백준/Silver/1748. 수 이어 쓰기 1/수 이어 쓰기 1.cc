#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Num, Count = 0;
	cin >> Num;
	for (int i = 1; i <= Num; i*= 10){
		//1부터 Num까지의 숫자들의 일의 자리 수 개수만 가져옴
		//10부터 Num까지의 숫저들의 십의 자리 수 개수만 가져옴
		// ... 반복
		Count += Num - i + 1;
	}
	cout << Count << "\n";
	return 0;
}