#include <iostream>
#include <vector>
#include <queue>
#define BEER 1000
using namespace std;

int GetDist(pair<int, int> a, pair<int, int> b);
//너비 우선 탐색
void BFS(pair<int,int> startPos, pair<int, int> endPos, vector<pair<int, int>> &map);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	int convis, start, end;
	pair<int, int> homePos, festiPos;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		vector<pair<int, int>> conviPos;
		cin >> convis;
		//집 위치
		cin >> homePos.first >> homePos.second;
		//편의점 위치
		for (int j = 0; j < convis; j++){
			cin >> start >> end;
			conviPos.push_back({start, end});
		}
		//축제 위치
		cin >> festiPos.first >> festiPos.second;

		BFS(homePos, festiPos, conviPos);
	}
	return 0;
}

int GetDist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void BFS(pair<int, int> startPos, pair<int, int> endPos, vector<pair<int, int>> &map) {
	queue<pair<int, int>> nxtPos;
	vector <bool> visited(map.size(), false);
	nxtPos.push({startPos.first, startPos.second});
	bool isPossible = false;
	while (!nxtPos.empty()) {
		if (GetDist(nxtPos.front(), endPos) <= BEER) {
			isPossible = true;
			break;
		}
		//편의점 찾기
		for (int i = 0; i < map.size(); i++){
			if (visited[i])
				continue;
			if (GetDist(nxtPos.front(), map[i]) <= BEER) {
				nxtPos.push({ map[i].first, map[i].second });
				visited[i] = true;
			}
		}
		nxtPos.pop();
	}
	if (isPossible)
		cout << "happy" << '\n';
	else
		cout << "sad" << '\n';
}