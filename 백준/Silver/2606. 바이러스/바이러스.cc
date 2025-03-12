#include <iostream>
using namespace std;

void DFS(int start, int total);

int nodes, bridges, result;
bool network[101][101];
bool computers[101] = {false,};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	result = 0;
	cin >> nodes >> bridges;

	//간선 설정
	for (int i = 0; i < bridges; i++){
		int start, end;
		cin >> start >> end;
		network[start][end] = true;
		network[end][start] = true;
	}

	DFS(1,nodes);

	cout << result << "\n";
	return 0;
}
//깊이 우선 탐색(재귀)
void DFS(int start, int total) {
	computers[start] = true;
	for (int i = 1; i <= total; i++){
		if (network[start][i] && !computers[i]) {
			result++;
			DFS(i, total);
		}
	}
	return;
}
