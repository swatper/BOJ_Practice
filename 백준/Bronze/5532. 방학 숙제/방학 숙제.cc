#include <iostream>
using namespace std;
//한 과목을 다 풀때까지 걸리는 기간 계산
int ReqDay(int TotalPage, int SolvePage) {
	if (TotalPage % SolvePage != 0) {
		return (TotalPage / SolvePage) + 1;
	}
	else
	{
		return TotalPage / SolvePage;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Vac, MathPage, KoreanPage, MathSolve, KoreanSolve, MathReq, KoreanReq, ReqVac;
	cin >> Vac >> MathPage >> KoreanPage >> MathSolve >> KoreanSolve;
	MathReq = ReqDay(MathPage, MathSolve);
	KoreanReq = ReqDay(KoreanPage, KoreanSolve);
	//두 과목 중 가장 오래걸린 기간 가져오기
	ReqVac = MathReq > KoreanReq ? MathReq : KoreanReq;
	cout << Vac - ReqVac << "\n";
	return 0;
}