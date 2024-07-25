#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int E, S, M, ResE = 0, ResS = 0, ResM = 0, Count = 0;
	cin >> E >> S >> M;
	while (true){
		//1년 흐름
		Count++;
		ResE++;
		ResS++;
		ResM++;
		//범위 확인
		if (ResE == 16) {
			ResE = 1;
		}
		if (ResS == 29) {
			ResS = 1;
		}
		if (ResM == 20) {
			ResM = 1;
		}
		//같은지 확인
		if (ResE == E && ResS == S && ResM == M) {
			cout << Count << "\n";
			break;
		}
	}
	return 0;
}