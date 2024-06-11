#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Sequence;
	int Size, Target,Count = 0;
	cin >> Size;
	for (int i = 0; i < Size; i++){
		int Temp;
		cin >> Temp;
		Sequence.push_back(Temp);
	}
	cin >> Target;
	//오름차순으로 정렬
	sort(Sequence.begin(), Sequence.end());
	int Front = 0, Back = Sequence.size() - 1;
	while (Front < Back){
		//두 수의 합 확인
		int Sum = Sequence[Front] + Sequence[Back];
		//합이 X(Target)보다 크면 뒤의 인덱스(큰 값)을 낮춤
		if (Sum > Target){
			Back--;
		}
		//합이 X(Tareget)보다 작으면 앞의 인덱스(작은 값)을 높임
		else if (Sum < Target) {
			Front++;
		}
		//같으면 쌍을 이룰 수 있으므로 Count값을 증가시킴
		//그 다음 값을 확인하기 위해 앞과 뒤의 인덱스 값을 조절
		else {
			Front++;
			Back--;
			Count++;
		}
	}
	cout << Count << "\n";
	return 0;
}