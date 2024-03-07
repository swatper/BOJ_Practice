#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //C랑 C++ 동기 X
	long long N, Clu, Result;
	Result = 0;
	cin >> N;
	long long* F = new long long[N]; //동적 할당
	for (int i = 0; i < N; i++) {
		cin >> F[i];
	}
	cin >> Clu;
	for (int i = 0; i < N; i++) {
		if (F[i] == 0) { //파일 크기가 0이면 공간차지 X
			continue;
		}
		int Tmp = F[i] / Clu; //몫
		if (F[i] % Clu != 0) {//나미지가 있으면
			Tmp += 1;
		}
		Result += Tmp * Clu;
	}
	cout << Result << "\n";
	return 0;
}