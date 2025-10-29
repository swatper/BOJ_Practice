#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int BFS(int start, int end, int max, vector<bool> visited);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Subin, Sibling;
	vector<bool> Visited(MAX, false);
	cin >> Subin >> Sibling;
	BFS(Subin, Sibling, MAX, Visited);
	cout << BFS(Subin, Sibling, MAX, Visited) << "\n";
	return 0;
}

//너비 우선 탐색
int BFS(int start, int end, int max, vector<bool> visited) {
	queue<pair<int, int>> nxtPos;
	int result = 0;
	nxtPos.push({start, 0});
	while (!nxtPos.empty()) {
		//현재 위치와 이동 횟수 가져오기
		int curPos = nxtPos.front().first;
		int curCnt = nxtPos.front().second;
		//도착 확인
		if (curPos == end) {
			result = curCnt;
			break;
		}
		//다음 위치로 갈 수 있는 곳을 모두 큐에 저장{현재 위치 , 이동횟수}
		if (curPos +1 < MAX) {
			if (!visited[curPos + 1]) 
				nxtPos.push({curPos + 1, curCnt + 1});
		}
		if (curPos - 1 >= 0) {
			if (!visited[curPos - 1]) 
				nxtPos.push({ curPos - 1, curCnt + 1});
		}
		if (curPos * 2 < MAX) {
			if (!visited[curPos  * 2])
				nxtPos.push({ curPos * 2, curCnt + 1});
		}
		//방문 확인
		visited[curPos] = true;
		nxtPos.pop();
	}
	return result;
}