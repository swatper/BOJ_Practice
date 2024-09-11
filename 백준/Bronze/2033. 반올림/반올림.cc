#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Num, Place = 10;
	cin >> Num;
	while (Num > Place) {
		int Temp = Num % Place;
		//반올림 여부 확인
		if (Temp > 4 * (Place / 10))
		{
			//반올림
			Num += Place;
		}
		//자릿수 0으로 바꾸기
		Num -= Temp;
		//자릿수 올리기
		Place *= 10;
	}
	cout << Num << "\n";
	return 0;
}