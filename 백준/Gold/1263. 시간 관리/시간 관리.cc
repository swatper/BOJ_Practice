#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//구조체 쓰기
struct Task{
	int reqTime;
	int deadLine;
};

bool Compare(Task a, Task b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tasks, t, d;
	cin >> tasks;
	vector<Task> schedule;
	for (int i = 0; i < tasks; i++){
		cin >> t >> d;
		schedule.push_back({t, d});
	}

	sort(schedule.begin(), schedule.end(), Compare);

	//데드라인이 가장 긴 시간 기준(= 사용 가능 시간)
	int maxSleepTime = schedule[0].deadLine;
	bool isPossble = true;
	for (int i = 0; i < tasks; i++){
		//다음 작업 데드라인으로 남은 시간 설정
		maxSleepTime = (maxSleepTime > schedule[i].deadLine) ? schedule[i].deadLine : maxSleepTime;
		//작업하기
		maxSleepTime -= schedule[i].reqTime;

		if (maxSleepTime < 0){
			isPossble = false;
			break;
		}
	}

	if (isPossble)
		cout << maxSleepTime << '\n';
	else
		cout << -1 << '\n';
	return 0;
}

//마감 시간이 긴 순서대로 정렬
bool Compare(Task a, Task b) {
	return a.deadLine > b.deadLine;
}