#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tileSize, stealTiles;
	cin >> tileSize >> stealTiles;
	for (int i = 0; i < stealTiles; i++){
		int x, y;
		cin >> x >> y;
		//해당 위치와 바깥까지의 최단거리 계산
		int xdist = x < (tileSize - x) ? x : (tileSize - x) + 1;
		int ydist = y < (tileSize - y) ? y : (tileSize - y) + 1;
		int dist = xdist < ydist ? xdist : ydist;
		//3가지 색이 반복되므로 최단 거리에서 3을 나눈 나머지로 색깔 파악
		cout << (dist - 1) % 3 + 1 << "\n";
	}
	return 0;
}
