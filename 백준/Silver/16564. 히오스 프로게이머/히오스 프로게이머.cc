#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(int a, int b);
bool CheckLevel(long long* list, int endIndex, long long targetLev, long long usableLev);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfHeroes;
	long long restLev, resultLev = 0 ;
	cin >> numOfHeroes >> restLev;
	long long* heroList = new long long[numOfHeroes];
	for (int i = 0; i < numOfHeroes; i++){
		cin >> heroList[i];
	}
	//오름차순 정렬
	sort(heroList, heroList + numOfHeroes, Compare);
	//이분 탐색
	long long lowLev = heroList[0];
	long long highLev = heroList[numOfHeroes - 1] + restLev;
	while (lowLev <= highLev) {
		long long midLev = (lowLev + highLev) / 2;
		if (CheckLevel(heroList, numOfHeroes, midLev, restLev)) {
			resultLev = midLev;
			lowLev = midLev + 1;
		}
		else {
			highLev = midLev - 1;
		}
	}
	cout << resultLev << "\n";
	return 0;
}

bool Compare(int a, int b) {
	return a < b;
}

bool CheckLevel(long long * list, int numOfList, long long targetLev, long long usableLev) {
	long long reqLev = 0;
	for (int i = 0; i < numOfList; i++) {
		//낮은 레벨이 목표 레벨이 되기까지 필요한 레벨량 계산
		if (list[i] < targetLev) {
			reqLev += (targetLev - list[i]);
			if (reqLev > usableLev){
				return false;
			}
		}
		else {
			break;
		}
	}
	return true;
}