#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfPeople, totalTime = 0;
	//각 사람의 인출 시간을 저장할 vector
	vector<int> P;

	cin >> numOfPeople;

	for (int i = 0; i < numOfPeople; i++){
		int reqTime;
		cin >> reqTime;
		P.push_back(reqTime);
	}

	//CPU 스케줄링 방법 중 최단 작업 우선 스케줄링(SJF) 사용
	//-> 작업 시간이 가장 적은 일부터 실행(여기서는 도착 시간 고려 X)
 
	//오름 차순 정렬
	sort(P.begin(), P.end());

	//시간 계산
		//i+1번재 고객의 인출 시간은 
		//i번째 고객의 인출 시간(기다리는 시간)과
		//i+1번째 고객의 인츨 시간(일하는 시간)의 합
			//-> P[i]의 시간을 (전체 사람의 수 - i번째) 만큼 더함
	for (int i = 0; i < numOfPeople; i++){
		totalTime += P[i] * (numOfPeople - i);
	}
	cout << totalTime << "\n";
	return 0;
}