#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//배열 동적 할당
	int* Size = new int[6];
	int SetT, SetP, ReqT = 0,ReqP = 0;

	//전체 인원수 == 필요한 연필의 수
	cin >> ReqP;

	//사이즈 별 인원수 입력 받기
	for (int i = 0; i < 6; i++){
		cin >> Size[i];
	}

	cin >> SetT >> SetP;

	for (int i = 0; i < 6; i++){
		ReqT += Size[i] / SetT;
		//(사람수 % 묶음)하였을 때 나머지가 있으면 한 묶음을 더 사야함
		if (Size[i] % SetT != 0){
			ReqT++;
		}
	}

	cout << ReqT << "\n";
	cout << ReqP / SetP << " " << ReqP % SetP << "\n";

	return 0;
}