#include <iostream>
#include <algorithm>
#define MAX 2000000000
using namespace std;
//백준
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Nums, MinGap, CurrentGap = MAX;
	cin >> Nums >> MinGap;
	int* NumsArray = new int[Nums];
	for (int i = 0; i < Nums; i++) {
		cin >> NumsArray[i];
	}
	//오름차순 정렬
	sort(NumsArray, NumsArray + Nums);
	int Front = 0, Back = 1;
	while (Front < Nums && Back < Nums) {
		//값 차이 확인
		int TempGap = NumsArray[Back] - NumsArray[Front];
		//최소 차이 MinGap 이상일 때
		if (TempGap >= MinGap) {
			//방금 계산한 차이 값과 현재의 차이 값을 비교하여 더 작은 값을 가져옴
			if (TempGap < CurrentGap) {
				CurrentGap = TempGap;
			}
			Front++;
		}
		//최소 차이 MinGap보다 값이 작으면, 더 큰 차이를 만들기 위해, Back을 옮김
		else {
			Back++;
		}
	}
	cout << CurrentGap << "\n";
	return 0;
}
//다시 공부하기