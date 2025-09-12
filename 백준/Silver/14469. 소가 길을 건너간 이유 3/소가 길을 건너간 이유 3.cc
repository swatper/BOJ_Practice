#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b);

//CPU 스케줄링의 FCFS 사용
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cows, totalTime = 0;
	int time, burst;
	vector<pair<int, int>> jobs;
	cin >> cows;
	for (int i = 0; i < cows; i++){
		cin >> time >> burst;
		jobs.push_back({time, burst});
	}
	//정렬
	sort(jobs.begin(), jobs.end(), Compare);

	while (!jobs.empty()) {
		pair<int, int> job = jobs.back();
		//대기 시간 계산(바로 처리 가능한 지, 기다려야 하는지)
		totalTime = totalTime > job.first ? totalTime : job.first;
		//작업 시간 계산
		totalTime += job.second;
		jobs.pop_back();
	}
	cout << totalTime << "\n";
}

//내림차순 정렬
bool Compare(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}
