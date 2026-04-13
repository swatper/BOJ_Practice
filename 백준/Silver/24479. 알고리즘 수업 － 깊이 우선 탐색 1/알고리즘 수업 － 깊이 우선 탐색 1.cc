#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int a, int b);
void DFS(vector<vector<int>>& graph, vector<int>& visited, int start);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int nodes, edges, start;
	cin >> nodes >> edges >> start;
	//그래프 생성 (각 노드별 간선, 인접 리스트)
	vector<vector<int>>graph(nodes + 1);
	//방문 여부
	vector<int> visited(nodes + 1, 0);

	//간선 입력 받기
	for (int i = 0; i < edges; i++){
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	//오름 차순 방문을 위한 정렬
	for (int i = 0; i < nodes + 1; i++){
		sort(graph[i].begin(), graph[i].end(), Compare);
	}

	//깊이 우선 탐색 시작
	DFS(graph, visited, start);

	//결과 확인
	for (int i = 1; i < nodes + 1; i++)
		cout << visited[i] << '\n';

	return 0;
}

bool Compare(int a, int b) {
	return a < b;
}

//Stack 이용 + 참조
void DFS(vector<vector<int>>& graph, vector<int>& visited, int start) {
	stack<int> nearNodes;
	nearNodes.push(start);
	int sequence = 1;
	while (!nearNodes.empty()) {
		int curNode = nearNodes.top();
		nearNodes.pop();

		//방문 여부 확인
		if (visited[curNode] != 0)
			continue;

		//방문 순서 메모
		visited[curNode] = sequence++;

		//간선 확인
		for (int i = graph[curNode].size() - 1; i >= 0; i--){
			int nextNode = graph[curNode][i];
			if (visited[nextNode] == 0)
				nearNodes.push(nextNode);
		}
	}
}