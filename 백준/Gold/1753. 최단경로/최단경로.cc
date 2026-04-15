#include <iostream>
#include <vector>
#include <queue>
#define INF 2147000000
using namespace std;

vector<pair<int, int>> graph[200001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int nodes, edges, start;
	int begin, end, weight;

	cin >> nodes >> edges >> start;
	vector<int> visited(nodes + 1, INF);

	for (int  i= 0; i < edges; i++){
		cin >> begin >> end >> weight;
		graph[begin].push_back({ end, weight });
	}

	//탐색 시작
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nearNodes;
	visited[start] = 0;
	//pair의 정렬 기준은 first값이라, {비용, 도착점}으로 저장
	nearNodes.push({0, start});
	while (!nearNodes.empty()) {
		//이동(도착) 후 거리 계산
		int curDist = nearNodes.top().first;
		int curNode = nearNodes.top().second;
		nearNodes.pop();
		//비용 확인
		if (visited[curNode] < curDist)
			continue;

		//근처 노드 확인
		for (int i = 0; i < graph[curNode].size(); i++) {
			int nextNode = graph[curNode][i].first;
			int nextDist = curDist + graph[curNode][i].second;
			//그래프 갱신
			if (nextDist < visited[nextNode]) {
				visited[nextNode] = nextDist;
				nearNodes.push({nextDist, nextNode});
			}
		}
	}

	for (int i = 1; i <= nodes; i++){
		if (visited[i] == INF)
			cout << "INF" << '\n';
		else
			cout << visited[i] << '\n';
	}

	return 0;
}