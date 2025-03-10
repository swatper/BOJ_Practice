#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	//2차원 배열 생성
	vector <vector <int>> map(N, vector<int>(M, 0));
	vector <vector <int>> result(N, vector<int>(M, 0));
	vector <vector <bool>> visited(N, vector<bool>(M, false));
	queue<pair<int, int>> Q;
	//왼쪽, 아래, 위, 오른쪽 좌표 
	int nearX[4] = { -1, 0, 0, 1 };
	int nearY[4] = { 0, 1, -1, 0 };
	//입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			//출발지 설정
			if (map[i][j] == 2) {
				Q.push({i , j});
				result[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}
	//탐색 시작 (너비 우선 탐색 -> 큐 사용)
	while (!Q.empty()) {
		int curX = Q.front().first;
		int curY = Q.front().second;
		//다음 이동할 좌표 설정
		for (int i = 0; i < 4; i++){
			int nextX = curX + nearX[i];
			int nextY = curY + nearY[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
				//방문 여부 설정
				visited[nextX][nextY] = true;
				result[nextX][nextY] = result[curX][curY] + 1;
				Q.push({nextX, nextY});
			}
		}
		Q.pop();
	}
	//결과 확인
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//도달할 수 없는 경우
			if (!visited[i][j] && map[i][j] != 0)
				cout << "-1 ";
			else
				cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}