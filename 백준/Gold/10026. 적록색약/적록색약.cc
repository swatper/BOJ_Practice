#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nearX[4] = { -1, 0, 0, 1 };
int nearY[4] = { 0, 1, -1, 0 };

void BFS(int& count, int size, string map[], vector<vector<bool>> Visited, bool Type);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int size, normal = 0, colorblind = 0;
	cin >> size;
	//그림 입력 받기
	string* painting = new string[size];
	for (int i = 0; i < size; i++){
		cin >> painting[i];
	}
	//탐색 준비
	vector<vector <bool>> visited(size, vector<bool>(size, false));
	//정상 기준 탐색
	BFS(normal, size, painting, visited, true);
	//색약 기준 탐색
	BFS(colorblind, size, painting, visited, false);
	cout << normal << ' ' << colorblind << '\n';
	delete[] painting; //메모리 해제
	return 0;
}

void BFS(int &count, int size, string map[], vector<vector<bool>>Visited, bool Type) {
	queue<pair<int, int>> nextPos;
	//전체 탐색
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Visited[i][j])
				continue;
			//깊이 우선 탐색 시작
			count++;
			nextPos.push({ i , j });
			Visited[i][j] = true;
			while (!nextPos.empty()) {
				char curColor = map[i][j];
				int curX = nextPos.front().second;
				int curY = nextPos.front().first;
				nextPos.pop();
				for (int k = 0; k < 4; k++) {
					int nextX = curX + nearX[k];
					int nextY = curY + nearY[k];
					//범위 및 방문 여부 확인
					if (nextX < 0 || nextX >= size || nextY < 0 || nextY >= size || Visited[nextY][nextX])
						continue;
					//정상
					if (Type) {
						if (curColor == map[nextY][nextX]) {
							Visited[nextY][nextX] = true;
							nextPos.push({nextY, nextX});
						}
					}
					//색약
					else {
						if ((curColor == 'R' || curColor == 'G') &&
							(map[nextY][nextX] == 'R' || map[nextY][nextX] == 'G')) {
							Visited[nextY][nextX] = true;
							nextPos.push({nextY, nextX});
						}
						else if (map[nextY][nextX] == curColor) {
							Visited[nextY][nextX] = true;
							nextPos.push({nextY, nextX});
						}
					}
				}
			}
		}
	}
}