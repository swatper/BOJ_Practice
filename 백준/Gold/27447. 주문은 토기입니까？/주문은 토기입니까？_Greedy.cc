#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int customers,meltTime;
	cin >> customers >> meltTime;
	int* arriveTime = new int[customers];
	for (int i = 0; i < customers; i++){
		cin >> arriveTime[i];
	}

	//시작
	int  makingIndex = 0, survingIndex = 0; //도착한 손님과 도착할 예정인 손님 index
	int cups = 0, coffee = 0;
	bool isPossible = true;
	for (int t = 0; t <= arriveTime[customers - 1]; t++){
		//서빙하기: 손님 도착 확인
		if (arriveTime[survingIndex] == t) {
			if (coffee == 0) {
				isPossible = false;
				break;
			}
			//커피 제공 및 다음 손님 설정
			else {
				coffee--;
				survingIndex++;
			}
		}
		//커피 내리기: 다음 올 손님 도착 및 컵 녹는 시간 확인
		else if (cups > 0 && makingIndex < customers && arriveTime[makingIndex] <= t + meltTime) {
			cups--;
			coffee++;
			makingIndex++;
		}
		//커피 잔 만들기
		else
			cups++;
	}

	if (isPossible)
		cout << "success" << '\n';
	else
		cout << "fail" << '\n';

	return 0;
}