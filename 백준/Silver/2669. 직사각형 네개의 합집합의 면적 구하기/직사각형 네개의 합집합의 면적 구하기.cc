#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x1, y1, x2, y2, size = 0;
	//2차원 배열(사각형)
	bool matrix[101][101] = { false,};
	for (int i = 0; i < 4; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		//2차원 배열 안에 실제 사각형을 색칠
		for (int x = x1; x < x2; x++){
			for (int y = y1; y < y2; y++)
			{
				//이미 색칠되어 있으면 넘어감
				if (matrix[x][y])
					continue;
				//색칠되어 있지 않으면 색칠 -> 칸(크기) 증가
				matrix[x][y] = true;
				size++;
			}
		}
	}
	cout << size << "\n";
	return 0;
}
