#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//상, 하, 좌, 우
int nearX[4] = { 0, 0, -1, 1 };
int nearY[4] = { -1, 1, 0, 0 };

//너비 우선 탐색
void BFS(queue<pair<int, int>> &target, vector<vector<int>>&graph, int width, int height);int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x, y, days = 0;
	cin >> x >> y;
	//토마토 익는 날을 저장할 배열
	vector<vector<int>> map(y, vector<int>(x)); 
	queue<pair<int, int>> tomatos;
	for (int a = 0; a < y; a++){
		for (int b = 0; b < x; b++){
			cin >> map[a][b];
			if (map[a][b] == 1)
				//익은 토마토(시작)만 저장
				tomatos.push({a, b});
		}
	}
	BFS(tomatos, map, x , y);
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			//안 익은 토마토 확인
			if (map[a][b] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			days = days > map[a][b] ? days : map[a][b];
		}
	}
	cout << days - 1<< '\n';
	return 0;
}

void BFS(queue<pair<int, int>>&target, vector<vector<int>>&graph, int width, int height) {
	//탐색 시작
	while (!target.empty()) {
		int curX = target.front().second;
		int curY = target.front().first;
		target.pop();
		//근처 토마토 확인
		for (int i = 0; i < 4; i++){
			int nxtX = curX + nearX[i];
			int nxtY = curY + nearY[i];
			if (nxtX >= 0 && nxtX < width &&
					nxtY >= 0 && nxtY < height &&
					graph[nxtY][nxtX] == 0) { //범위 확인 및 토마토 유무 확인
				graph[nxtY][nxtX] = graph[curY][curX] + 1;
				target.push({nxtY, nxtX});
			}
		}
	}
}