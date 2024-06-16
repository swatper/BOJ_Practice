#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		int	Sang, Seon, Count = 0;
		vector<int> SangCD;
		vector<int> SeonCD;
		cin >> Sang >> Seon;
		if (Sang == 0 && Seon == 0){
			return 0;
		}
		//상근이의 CD 목록 입력 받기
		for (int i = 0; i < Sang; i++){
			int CDNum;
			cin >> CDNum;
			//배열에 추가
			SangCD.push_back(CDNum);
		}
		//선영이의 CD 목록 입력받기
		for (int i = 0; i < Sang; i++){
			int CDNum;
			cin >> CDNum;
			//배열에 추가
			SeonCD.push_back(CDNum);
		}
		//투포인터 사용
		int SangIndex = 0, SeonIndex = 0;
		while (SangIndex < Sang && SeonIndex < Seon){
			if (SangCD[SangIndex] < SeonCD[SeonIndex]){
				SangIndex++;
			}
			else if (SangCD[SangIndex] > SeonCD[SeonIndex]) {
				SeonIndex++;
			}
			else {
				SangIndex++;
				SeonIndex++;
				Count++;
			}

		}
		cout << Count << "\n";
	}
	return 0;
}    
/*map을 이용하니 시간초과 발생*/