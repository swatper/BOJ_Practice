#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int size;
	cin >> size;

	int rows = 2 * size;
	int cols = 4 * size + 2;

	for (int r = 0; r < rows; r++) {
		//왼쪽 대각선 위치: ↙ 모양
		int leftStar = rows - r;
		//다이아몬드 위치
		int offset = 2 * (size + 1);
		int line = (r < size) ? r : (rows - 1 - r);
		//왼쪽 별 위치: 
		int leftDiamond = (size - 1 - line) + offset;
		//공백 수: 1행 1개, 2행 3개 3행 5개 .... 
		int diamondBlank = (line * 2) + 1;
		//오른쪽 별은 항상 (왼쪽 별 위치 )+ (공백 갯수) 후에 있음
		int rightDiamond = leftDiamond + diamondBlank + 1;

		for (int i = 1; i <= cols; i++) {
			if (i == leftStar || i == leftDiamond || i == rightDiamond)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}