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
	int NumOfAqua, MaxGap = MAX, AquaA = 0, AquaB = 0;
	//재료의 종류와 제작하는데 필요한 제료 수 입력 받기
	cin >> NumOfAqua;
	int* AquaArray = new int[NumOfAqua];
	//재료의 종류별 갯수 입력받기
	for (int i = 0; i < NumOfAqua; i++) {
		cin >> AquaArray[i];
	}
	int Front = 0, Back = NumOfAqua - 1;
	//오름 차순으로 정렬
	sort(AquaArray, AquaArray + NumOfAqua);

	while (Front < Back){
		//농도 차이 값 구하기 (절댓값)
		int TemGap = abs(AquaArray[Front] + AquaArray[Back]);
		//가장 작은 농도 차이 찾기
		if (TemGap < MaxGap)  {
			MaxGap = TemGap;
			AquaA = AquaArray[Front];
			AquaB = AquaArray[Back];
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
	cout << AquaA << " " << AquaB << "\n";
	return 0;
}