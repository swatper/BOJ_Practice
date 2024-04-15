#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Nums, GoodNums = 0;
	cin >> Nums;
	int* NumArray = new int[Nums];
	for (int i = 0; i < Nums; i++) {
		cin >> NumArray[i];
	}
	//오름 차순 정렬
	sort(NumArray, NumArray + Nums);
	//배열 안에 있는 각각의 숫자가 좋은 숫자인지 확인
	for (int i = 0; i < Nums; i++) {
		//좋은 숫자인지 확인할 타켓 설정
		int Target = NumArray[i];
		int Front = 0, Back = Nums - 1;
		//타켓이 좋은 숫자인지 확인(투 포인터)
		while (Front < Back) {
			//두 수의 합이 타켓과 같은 경우
			if (NumArray[Front] + NumArray[Back] == Target) {
				//타켓 본인은 제외 시켜야 함
				if (Front == i) {
					Front++;
				}
				else if (Back == i) {
					Back--;
				}
				else{
					GoodNums++;
					break;
				}
			}
			//두 수의 합이 타겟보다 작으면 Front의 값을 증가시켜 더 큰 값을 사용하도록 함
			else if (NumArray[Front] + NumArray[Back] < Target) {
				Front++;
			}
			//두 수의 합이 타겟보다 크면 Back의 값을 감소시켜 더 작은 값을 사용하도록 함
			else {
				Back--;
			}
		}
	}
	cout << GoodNums << "\n";
	return 0;
}