#include <vector>
#include <queue>
using namespace std;

//좌,하,상,우
int nearX[4] = { -1, 0, 0, 1 };
int nearY[4] = { 0, 1, -1, 0 };

int solution(vector<vector<int> > maps) {
	int width = maps[0].size(), height = maps.size();
	//다음 방문할 곳
	queue<int> nxtPos;
	maps[0][0] = 1;
	//탐색 시작
	nxtPos.push(0);
	while (!nxtPos.empty()) {
		int curPos = nxtPos.front();
		int curY = curPos / width;
		int curX = curPos % width;
		//도착 지점 확인
		if (curY == height - 1 && curX == width - 1)
			return maps[curY][curX];

		nxtPos.pop();

		//근처 길 확인
		for (int i = 0; i < 4; i++) {
			int nxtX = curX + nearX[i];
			int nxtY = curY + nearY[i];
			if (nxtX >= 0 && nxtX < width && nxtY >= 0 && nxtY < height) {
				if (maps[nxtY][nxtX] == 1) {
					//거리 기록
					maps[nxtY][nxtX] = maps[curY][curX] + 1;
					nxtPos.push(nxtY * width + nxtX);
				}
			}
		}
	}
    return -1;
}
