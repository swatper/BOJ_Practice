#include <iostream>
#include <algorithm>
#include <cmath>
//농도 차이 최댓값
#define MAX 2000000000
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NumOfAqua, MaxGap = MAX;
	cin >> NumOfAqua;
	int* AquaArray = new int[NumOfAqua];
	for (int i = 0; i < NumOfAqua; i++) {
		//용액 값 입력 받기
		cin >> AquaArray[i];
	}
	int Front = 0, Back = NumOfAqua - 1;
	//오름 차순으로 정렬
	sort(AquaArray, AquaArray + NumOfAqua);

	while (Front < Back) {
		//용액 합성 값 구하기 (절댓값)
		int TemGap = abs(AquaArray[Front] + AquaArray[Back]);

		//가장 작은 용액 합성값 구하기
		//가장 작은 값이 음수일 수도 있기 떄문에
		//MaxGap의 절댓값과 TempGap의 절댓값을 비교해야 함
		if (TemGap < abs(MaxGap)) {
			//abs(MaxGap)와 abs(TempGap)을 비교하여 가장 작은 값을 선택해야 함
			MaxGap = AquaArray[Front] + AquaArray[Back];
			//차이가 0이면 더이상 돌릴 필요가 없음
			if (MaxGap == 0) {
				break;
			}
		}
		//농도 차이가 클 때
		//절댓값을 비교하였을 때, 절댓값이 큰 값을 줄어야 함
		else if (abs(AquaArray[Front]) < abs(AquaArray[Back])) {
			Back--;
		}
		else {
			Front++;
		}

	}
	cout << MaxGap << "\n";
	return 0;
}