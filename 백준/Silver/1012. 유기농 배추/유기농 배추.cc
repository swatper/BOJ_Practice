#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc, sizeX, sizeY, Cabages, plantX, plantY;
	cin >> Tc;

	for (int i = 0; i < Tc; i++){
		int count = 0;
		cin >> sizeX >> sizeY >> Cabages;
		//2차원 배열 만들기
		vector<vector <int>> Filed(sizeX, vector<int>(sizeY, 0));
		vector<vector <bool>> Visited(sizeX, vector<bool>(sizeY, false));
		queue<pair<int, int>> CabageList;
		int nearX[4] = {-1, 0, 0, 1 };
		int nearY[4] = {0, 1, -1, 0};
		//배추 심기
		for (int j = 0; j < Cabages; j++){
			cin >> plantX >> plantY;
			Filed[plantX][plantY] = 1;
		}

		//탐색
		for (int a = 0; a < sizeX; a++){
			for (int b = 0; b < sizeY; b++){
				if (Filed[a][b] != 0 && !Visited[a][b]){
					Visited[a][b] = true;
					CabageList.push({a, b});
					count++;
				}
				//깊이 우선 탐색
				while (!CabageList.empty()) {
					int curX = CabageList.front().first;
					int curY = CabageList.front().second;

					for (int c = 0; c < 4; c++){
						int nextX = curX + nearX[c];
						int nextY = curY + nearY[c];
						if (nextX >= 0 && nextX < sizeX && nextY >= 0 && nextY < sizeY && Filed[nextX][nextY] == 1 && !Visited[nextX][nextY]) {
							//방문 여부 설정
							Visited[nextX][nextY] = true;
							CabageList.push({ nextX, nextY });
						}
					}
					CabageList.pop();
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}