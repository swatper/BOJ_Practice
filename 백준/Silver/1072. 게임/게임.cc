#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long Rec;		//판수
	long long Win;		//승리 횟수
	long long N = 0;	//승률이 변화하는 최소의 판수
	long long Rate1;	//현제 승률
	long long Rate2;	//변화한 승률
	cin >> Rec >> Win;
	Rate1 = (Win * 100) / Rec;	
	if (Rate1 >= 99) {	//승률이 99퍼센트 이상이면 승률 변화 없음
		cout << "-1" << endl;
		return 0;
	}
	//승률 변화가 있는 경우
	//이분탐색으로 해야 시간초과를 방지할 수 있음
	long long L = 0;			//최솟값
	long long H = 1000000000;   //최댓값
	while (L <= H) {
		long long M = (L + H) / 2;				//최대 판수와 최소 판수의 사이값을 가져옴 (이분)
		Rate2 = ((Win + M) * 100) / (Rec + M); 		//승률 계산
		if (Rate1 >= Rate2) {					//변화한 승률이 작을 경우
			N = M;
			L = M + 1; //최소값이 사이값보다 작게해서 계산해야할 판수를 반으로 줄임
		}
		else {									//변화한 승률이 클 경우
			H = M - 1; //최댓값 사이값보다 크게해서 계산해야할 판수를 반으로 줄임
		}
	}
	cout << N+1 << endl;

	return 0;
}