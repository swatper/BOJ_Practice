#include <iostream>
#define MAX 1000000000
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++) {
		unsigned long long Level = 1;		 //현재 레벨
		unsigned long long Monster_Exp = 1;//현재 몬스터 경험치
		unsigned long long Req_Exp = 2;	//현제 랩업을 위한 경험치
		unsigned long long Total_Exp = 0; //전체 경험치
		unsigned long long Total_Req_Exp = 0;//전체 필요한 경험치
		unsigned long long Kills;			//잡은 몬스터의 수
		cin >> Kills;

		if (Kills <= 1) {
			cout << 1 << "\n";
		}
		else{
			//등차수열의 합 (첫항이 1이고 공차가 1인 등차수열의 합)	
			Total_Exp = Kills * (Kills + 1) / 2;
			//이분탐색 사용
			unsigned long long L = 0;
			unsigned long long R = MAX ;
			while (L <= R) {
				unsigned long long M = (L + R) / 2;
				//등차수열의 합 (첫항이 2고 공차가 2인 등차수열의 합)
				Total_Req_Exp = M * (2 * Req_Exp + (M - 1) * 2) / 2;
				if (Total_Exp >= Total_Req_Exp) {
					Level = M;
					L = M + 1;
				}
				else {
					R = M - 1;
				}
			}
			cout << Level+1 << "\n";
		}
	}
	return 0;
} 