#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>& nodes, int start, int end, int size);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int cities, buses, start, end;
	int busStart, busEnd, dist;
	cin >> cities >> buses;
	//버스 정보를 저장할 배열
	vector<vector<pair<int, int>>>busData(cities + 1);
	vector<int> cityShortest(cities + 1, INF);
	for (int i = 0; i < buses; i++){
		cin >> busStart >> busEnd >> dist;
		busData[busStart].push_back({ busEnd, dist });
	}
	cin >> start >> end;
	Dijkstra(busData, cityShortest, start, end, cities);
	cout << cityShortest[end] << '\n';
	return 0;
}

void Dijkstra(vector<vector<pair<int, int>>>&graph, vector<int>& nodes, int start, int end, int size) {
	nodes[start] = 0;
	//우선순위 큐(첫 번째 인가 기준이기 때문에, {거리, 노드} 순서로 저장)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nxtnodes;
	nxtnodes.push({0, start});
	while (!nxtnodes.empty()) {
		int curNode = nxtnodes.top().second;
		int curDist = nxtnodes.top().first;
		nxtnodes.pop();

		if (nodes[curNode] < curDist)
			continue;
		//인접 노드 찾아서 거리 업데이트 및 다음 지점 저장
		for (int i = 0;  i < graph[curNode].size() ; i++){
			int nxtNode = graph[curNode][i].first;
			int nxtDist = curDist +  graph[curNode][i].second;
			if (nodes[nxtNode] > nxtDist) {
				nodes[nxtNode] = nxtDist;
				nxtnodes.push({ nxtDist, nxtNode});
			}
		}
	}
}