#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int X1, Y1, R1, X2, Y2, R2, ResultX = 0, ResultY = 0;;
	cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
	//-999부터 999까지 이중 for문을 돌려 X 와 Y값 찾기
	for (int X = -999; X <= 999; X++ ) {
		for (int Y = -999; Y <= 999; Y++) {
			if ((X * X1 + Y * Y1 == R1) && (X * X2 + Y * Y2 == R2)) {
				ResultX = X;
				ResultY = Y;
				break;
			}
		}
	}
	cout << ResultX << " " << ResultY << "\n";
	return 0;
}