#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& graph, vector<int>& visited, int start);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int friends, connect;
	int friendNum, fFriendNum;
	cin >> friends >> connect;

	//깊이 저장용
	vector<int> friendDist(friends + 1,  -1);
	//그래프 초기화(인접 노드)
	vector<vector<int>> friendNetwork(friends + 1);

	for (int i = 0; i < connect; i++){
		cin >> friendNum >> fFriendNum;
		//인접 노드만 저장
		friendNetwork[friendNum].push_back(fFriendNum);
		friendNetwork[fFriendNum].push_back(friendNum);
	}
	
	cout << BFS(friendNetwork, friendDist, 1) << '\n';
	return 0;
}

int BFS(vector<vector<int>> &graph, vector<int> &visited, int start) {
	queue<int> nearNodes;
	int result = 0;
	visited[start] = 0;
	nearNodes.push(start);
	while (!nearNodes.empty()) {
		int target = nearNodes.front();
		nearNodes.pop();

        //깊이 확인
		if (visited[target] >= 2)
			continue;

		int nextNode;
		//특정 친구 기준 친구들(친구의 친구) 찾기
		for (int i = 0; i < graph[target].size(); i++){
			nextNode = graph[target][i];
			if (visited[nextNode] == -1) {
				visited[nextNode] = visited[target] + 1;
				nearNodes.push(nextNode);
				result++;
			}
		}
	}
	return result;
}