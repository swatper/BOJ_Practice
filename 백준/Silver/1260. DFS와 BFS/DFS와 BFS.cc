#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int Node, int Nodes, bool* DFSVisitedMap, const vector<vector<bool>>& Edge);
void BFS(int Node, int Nodes, bool* BFSVisitedMap, const vector<vector<bool>>& Edge);

//트리 탐색 연습 2
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//간선을 저장할 변수
	vector<vector<bool>> Edge(1001, vector<bool>(1001, 0));
	//방문 여부를 확인할 변수
	bool DFSVisitedMap[1001] = { false, };
	bool BFSVisitedMap[1001] = { false, };

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++){
		int Node1, Node2;
		cin >> Node1 >> Node2;
		//간선 설정
		Edge[Node1][Node2] = true;
		Edge[Node2][Node1] = true;
	}
	DFS(V, N, DFSVisitedMap, Edge);
	cout << "\n";
	BFS(V, N, BFSVisitedMap, Edge);
	cout << "\n";
	return 0;
}    

//깊이 우선 탐색
void DFS(int Node, int Nodes, bool* DFSVisitedMap, const vector<vector<bool>> &Edge) {
	//방문한 노드 출력
	cout << Node << " ";
	//방문 기록(?)
	DFSVisitedMap[Node] = true;
	//간선 유무 확인
	for (int i = 1; i <= Nodes; i++){
		//간선이 존재하고 방문하지 않으면 방문
		if (Edge[Node][i] && DFSVisitedMap[i]!= true) {
			//재귀
			DFS(i, Nodes, DFSVisitedMap, Edge);
		}
	}
	return;
}

//너비 우선 탐색
void BFS(int Node, int Nodes, bool* BFSVisitedMap, const vector<vector<bool>>& Edge) {
	//인접한 노드를 저장할 queue
	queue<int> AdjacentNodes;
	//방문한 노드 출력
	cout << Node << " ";
	//방문 기록(?)
	BFSVisitedMap[Node] = true;
	AdjacentNodes.push(Node);
	while (!AdjacentNodes.empty()){
		Node = AdjacentNodes.front();
		AdjacentNodes.pop();
		for (int i = 1; i <= Nodes; i++) {
			//자식 노드 확인
			if (Edge[Node][i] && BFSVisitedMap[i] != true) {
				AdjacentNodes.push(i);
				BFSVisitedMap[i] = true;
				cout << i << " ";
			}
		}
	}
	return;
}