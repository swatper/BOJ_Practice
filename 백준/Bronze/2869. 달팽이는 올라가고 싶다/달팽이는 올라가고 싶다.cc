#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	unsigned int A, B, V, Days;
	cin >> A >> B >> V;
	//첫 날 이동 거리
	Days = 1;
	V = V - A;
	//남은 거리 계산
	Days = Days + (V / (A - B));
	if (V % (A-B) != 0) {
		Days += 1;
	}
	cout << Days << "\n";
	return 0;
}