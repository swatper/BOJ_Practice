#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int meetings, cnt = 0;
	unsigned int start, end, curTime = 0;
	vector<pair<unsigned int, unsigned int>>schedule;
	cin >> meetings;
	for (int i = 0; i < meetings; i++){
		cin >> start >> end;
		schedule.push_back({start, end});
	}
	//종료 시간 기준으로 정렬
	sort(schedule.begin(), schedule.end(), Compare);
	for (int i = 0; i < meetings; i++){
		//현재 시간 기준으로 가장 빨리 끝나는 회의 찾기
		if (curTime <= schedule[i].first) {
			curTime = schedule[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}

bool Compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b) {
	//종료 시간이 같으면 회의 시작 시간 기준으로 정렬
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}