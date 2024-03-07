#include <iostream>
using namespace std;

int main() {
	float A, B, C, D, Max;
	int index = 0;
	cin >> A >> B >> C >> D;
	//각각의 경우를 모두 계산해서 배열에 저장
	float NumArray[4] = { ((A / C) + (B / D)),((C / D) + (A / B)),((D / B) + (C / A)),((B / A) + (D / C)) };
	Max = NumArray[0];
	//값 비교해서 가장 큰 값의 인덱스 구하기
	for (int i = 1; i < 4; i++) {
		if (Max < NumArray[i]) {
			Max = NumArray[i];
			index = i;
		}
	}
	cout << index << "\n";
	return 0;
}