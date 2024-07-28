#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc, N, M;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		cin >> N >> M;
		//이항 정리 문제
		int Result = 1;
		int Tmp = 1;
		for (int j = M; j > M - N; j--){
			Result *= j;
			Result /= Tmp++;
		}
		cout << Result << "\n";
	}
	return 0;
}