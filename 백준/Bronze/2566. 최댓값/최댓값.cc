#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	//2차원 배열 생성
	int NumArray[10][10] = {};
	int Row, Column, Max = -1;
	//값 입력받기
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			//값을 입력받을때 마다 저장
			cin >> NumArray[i][j];
			//만약 최대값이 입력 받은 값보다 작으면 해당 index에 있는 값과 index를 저장
			if (Max < NumArray[i][j]) {
					Max = NumArray[i][j];
					Row = i;
					Column = j;
			}
		}
	}
	cout << Max << "\n" << Row << " " << Column << "\n";
	return 0;
}