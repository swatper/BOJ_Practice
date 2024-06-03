#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Fractures, Volumes;
	cin >> Fractures >> Volumes;
	int* Pot = new int[Fractures];

	//입력받기
	for (int i = 0; i < Fractures; i++){
		cin >> Pot[i];
	}

	//계산
	int Front = 0, Back = 0, CurrentV = Pot[0], MaxV = -1;
	while (Back < Fractures){
		//부피가 작으면
		if (CurrentV <= Volumes){
			MaxV = MaxV >= CurrentV ? MaxV : CurrentV;
			//범위 증가
			CurrentV += Pot[++Back];
		}
		//부피가 너무 크면
		else {
			//범위 감소
			CurrentV -= Pot[Front++];
		}
	}
	cout << MaxV << "\n";
	return 0;
}