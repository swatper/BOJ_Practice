#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 200000001
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){

		int Nums, Target, Count = 0;
		cin >> Nums >> Target;
		int* NumArray = new int[Nums];
		//수 입력받기
		for (int j = 0; j < Nums; j++){
			cin >> NumArray[j];
		}

		//오름차순 정렬
		sort(NumArray, NumArray + Nums);

		//찾기
		int Gap = MAX, Front = 0, Back = Nums - 1;
		while (Front < Back){
			//두 수의 합 계산
			int TempGap = NumArray[Front] + NumArray[Back];
			//해당 숫자에 가까운지 확인
			if (TempGap > Target){
				Back--;
			}
			else if (TempGap < Target) {
				Front++;
			}
			//같을 경우
			else{
				Front++;
				Back--;
			}
			//가까운 값
			if (abs(Target - (TempGap)) < Gap) {
				//다르면 가까운 값 갱신 
				Gap = abs(Target - (TempGap));
				Count = 1;
			}
			//같으면 가까운 값에 대한 조합 추가
			else if (abs(Target - (TempGap)) == Gap){
				Count++;
			}
		}
		cout << Count <<"\n";
	}
	return 0;
}