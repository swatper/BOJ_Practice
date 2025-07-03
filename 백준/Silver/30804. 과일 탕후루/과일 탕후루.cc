#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int fruits;
	//연속된 탕후르 내에 과일 종류와 개수를 저장할 배열
	int fruitType[10] = { 0, };
	cin >> fruits;

	int* tang = new int[fruits];
	for (int i = 0; i < fruits; i++){
		cin >> tang[i];
	}

	//탐색 시작
	int maxLength = 0;
	int front = 0, back = 0;
	while (back < fruits) {
		//탕후르에 꽂혀있는 과일의 종류와 개수 증가
		fruitType[tang[back]]++;

		//종류가 다른 과일의 수 계산
		int fruitTypes= 0;
		for (int i = 1; i < 10; i++){
			if (fruitType[i] > 0) {
				fruitTypes++;
			}
		}

		//과일 종류가 2개 이하가 될때까지 반복
		while (fruitTypes > 2) {
			//가장 왼쪽에 있는 과일 제거
			fruitType[tang[front]]--;

			// 제거한 과일의 개수가 0이 되면 과일 종류 감소
			if (fruitType[tang[front]] == 0) {
				fruitTypes--;
			}
			front++; 
		}

		int curLenth = back - front + 1;
		maxLength = (curLenth > maxLength) ? curLenth : maxLength;

		back++;
	}

	cout << maxLength;
	return 0;
}
