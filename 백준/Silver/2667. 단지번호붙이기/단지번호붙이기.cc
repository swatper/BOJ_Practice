#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int nearX[4] = { -1, 0, 0, 1 };
int nearY[4] = { 0, 1, -1, 0 };

//너비 우선 탐색
void BFS(int size, string map[], vector<vector<bool>> Visited);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int size;
	cin >> size;
	vector<vector <bool>> visited(size, vector<bool>(size, false));
	string* map = new string[size];
	for (int i = 0; i < size; i++) {
		cin >> map[i];
	}
	BFS(size, map, visited);

	delete[]map;
	return 0;
}

void BFS(int size, string map[], vector<vector<bool>>Visited) {
	int cpxNum = 0;					//단지 수(번호) 관리용
	vector<int> cpxBuildings;	//각 단지의 건물 수 관리용
	queue<pair<int, int>> nextPos;

	//단지 수 관리
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++){
			if (map[i][j] == '1' && !Visited[i][j]) {
				Visited[i][j] = true;
				//단지 수 증가
				cpxNum++;
				cpxBuildings.push_back(0);
				nextPos.push({i, j});
			}

			//탐색
			while (!nextPos.empty()) {
				int curX = nextPos.front().first;
				int curY = nextPos.front().second;
				//건물 수 증가
				cpxBuildings[cpxNum - 1]++;

				//근처 건물 확인
				for (int k = 0; k < 4; k++){
					int nextX = curX + nearX[k];
					int nextY = curY + nearY[k];
					if (nextX >= 0 && nextX < size && nextY >= 0 && nextY < size && map[nextX][nextY] == '1' && !Visited[nextX][nextY]) {
						Visited[nextX][nextY] = true;
						nextPos.push({nextX, nextY});
					}
				}
				nextPos.pop();
			}
		}
	}

	//정렬
	sort(cpxBuildings.begin(), cpxBuildings.end());
	cout << cpxNum << '\n';
	for (int i = 0; i < cpxNum; i++){
		cout << cpxBuildings[i] << '\n';
	}
}