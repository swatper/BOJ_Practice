#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int* List = new int[12];
	List[0] = 0;
	List[1] = 1;
	List[2] = 2;
	List[3] = 4;
	//규칙성: 4 이상부터 i는 (i - 3번쨰의 표현 방법) + (i - 2번쨰의 표현 방법) + (i - 1번쨰의 표현 방법)
	//을 한 값과 같음
	for (int i = 4; i < 12; i++){
		List[i] = List[i - 3] + List[i - 2] + List[i - 1];
	}
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		int Num;
		cin >> Num;

		cout << List[Num] << "\n";
	}
	return 0;
}