#include <iostream>
#include <deque>
#include <vector>
#define MAX 100001
#define BIGNUM 2100000000
using namespace std;

int BFS(int start, int end, int max, vector<int> &visited);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Subin, Sibling;
	//현재 위치(인데스)에 도착하기까지 걸리는 횟수를 저장
	vector<int> Visited(MAX, BIGNUM);
	cin >> Subin >> Sibling;
	cout << BFS(Subin, Sibling, MAX, Visited) << "\n";
	return 0;
}

//너비 우선 탐색
int BFS(int start, int end, int max, vector<int> &visited) {
	deque<int> movement;
	visited[start] = 0;
	movement.push_front(start);
	while (!movement.empty()) {
		//현재 위치와 이동 횟수 가져오기
		int curPos = movement.front();
		int curCnt = visited[curPos];

		movement.pop_front();

		if (curPos == end) {
			return visited[curPos];
		}

		int nxtPos = curPos * 2;
		//다음 위치로 갈 수 있는 곳을 모두 큐에 저장
		if (nxtPos < MAX) {
			//새로 온  경로(방법)이 더 짧으면 그 횟수로 초기화(최단거리)
			if (visited[nxtPos] > curCnt) {
				visited[nxtPos] = curCnt;
				movement.push_front({ nxtPos });
			}
		}

		nxtPos = curPos + 1;
		if (nxtPos < MAX) {
			if (visited[nxtPos] > curCnt + 1) {
				visited[nxtPos] = curCnt + 1;
				movement.push_back({ nxtPos });
			}
		}

		nxtPos = curPos - 1;
		if (nxtPos >= 0) {
			if (visited[nxtPos] > curCnt + 1) {
				visited[nxtPos] = curCnt + 1;
				movement.push_back({ nxtPos });
			}
		}
	}
}