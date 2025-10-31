#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//깊이 우선 탐색
void DFS(int start, vector<vector<int>> &graph, vector<bool>&visited);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int nodes, edges, cnt = 0;
	cin >> nodes >> edges;
	//간선을 저장 (인접 리스트 방식)
	vector<vector<int>> graph(nodes + 1);
	//방문 여부 확인
	vector<bool> visited(nodes + 1, false);

	for (int i = 0; i < edges; i++){
		int start, end;
		cin >> start >> end;
		//각 정점 기준으로 인접한 노드들을 저장
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int i = 1; i <= nodes; i++){
		if (!visited[i]) {
			DFS(i ,graph ,visited);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}

void DFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
	stack<int> nxtNodes;
	nxtNodes.push(start);
	//깊이 우선 탐색 시작
	while (!nxtNodes.empty()) {
		int curNode = nxtNodes.top();
		visited[curNode] = true;
		nxtNodes.pop();
		//인접 노드 탐색
			//현재 노드 기준으로 인덱스 안에 들어있는 원소(= 인접 노드) 탐색
		for (int i : graph[curNode]) { //이터레이터 사용
			if (!visited[i]) {
				nxtNodes.push(i);
			}
		}
	}
}
//속도  향상을 위한 기존의 인접 행렬 방식이 아닌 인접 리스트 방식으로 구현