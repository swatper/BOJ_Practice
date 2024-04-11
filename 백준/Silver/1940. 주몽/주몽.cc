#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Materials, ReqMaterials, Armors = 0;
	//재료의 종류와 제작하는데 필요한 제료 수 입력 받기
	cin >> Materials >> ReqMaterials;
	int* MaterialsArray = new int[Materials];
	//재료의 종류별 갯수 입력받기
	for (int i = 0; i < Materials; i++) {
		cin >> MaterialsArray[i];
	}
	//오름차순으로 정렬
	sort(MaterialsArray, MaterialsArray + Materials);
	int Front = 0, Back = Materials - 1;
	//가장 적은 재료의 갯수와 가장 많은 재료의 갯수를 더해서 갑옷을 만들 수 있는지 없는지 확인
	while (Front < Back){
		//더했을 때, 제작하는데 필요한 재료의 갯수와 같으면 제작 가능
		if (MaterialsArray[Front] + MaterialsArray[Back] == ReqMaterials) {
			Armors++;
			//다음으로 많은 재료와 적은 재료를 사용하기 위해 index 변경
			Front++;
			Back--;
		}
		else  if (MaterialsArray[Front] + MaterialsArray[Back] < ReqMaterials){
			//재료가 부족해서 갑옷을 만들 수 없음
			Front++;
		}
		else {
			//재료가 너무 많아서 갑옷을 만들 수 없음
			Back--;
		}
	}
	cout << Armors << "\n";
	return 0;
}