#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned int HoleSize;
	//아무것도 입력받지 않으면 종료
	while (cin >> HoleSize){
		//나노미터로 단위 바꾸기
		HoleSize *= 10000000;
		//레고 갯수
		int Lego;
		cin >> Lego;
		//배열 생성
		unsigned int* LegoList = new unsigned int[Lego];
		//레고 길이 입력받기
		for (int i = 0; i < Lego; i++){
			cin >> LegoList[i];
		}
		//오름차순 정렬
		sort(LegoList, LegoList+ Lego);
		//탐색 시작
		int Front = 0, Back = Lego - 1;
		bool IsSame = false;
		while (Front < Back){
			//합 계산
			unsigned int Total = LegoList[Front] + LegoList[Back];
			if (Total > HoleSize){
				Back--;

			}
			else if (Total < HoleSize) {
				Front++;
			}
			else {
				//|ℓ1 - ℓ2|가 가장 큰 것만 출력하면 되므로 추가 과정 필요 없음
				IsSame = true;
				break;
			}
		}
		if(IsSame){
			cout << "yes " << LegoList[Front] << " " << LegoList[Back] << "\n";
		}
		else {
			cout << "danger\n";
		}
	}
	return 0;
}