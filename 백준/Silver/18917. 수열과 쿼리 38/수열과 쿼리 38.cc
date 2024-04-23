#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned long long Total = 0;
	int Commands, Bit = 0;
	cin >> Commands;
	//쿼리할 때마다, 연산 진행
	for (int i = 0; i < Commands; i++) {
		int Query, Num;
		cin >> Query;
		switch (Query){
			//배열에 원소를 추가
			case 1:
				cin >> Num;
				//전체 합 증가
				Total += Num;
				//^는 XOR 연산
				Bit ^= Num;
				break;
			//배열에 원소를 삭제
			case 2:
				cin >> Num;
				//전체 합 감소
				Total -= Num;
				//XOR 연산을 통해 해당 비트만 반전 시킬 수 있음
				Bit ^= Num;
				break;
			case 3:
				cout << Total << "\n";
				break;
			case 4:
				cout << Bit <<"\n";
				break;
		}
	}
	return 0;
}