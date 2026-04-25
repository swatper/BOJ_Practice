#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct SCVState {
	int scv[3] = {0, 0, 0};
};

vector<vector<vector<int>>> SCVStateMap(61, vector<vector<int>>(61, vector<int>(61, -1)));
int Damage[6][3] = { //공격 유형
	{9, 3, 1}, {9, 1, 3},
	{3, 9, 1}, {3, 1, 9},
	{1, 9, 3}, {1, 3, 9}
}; 

void BFS(SCVState start);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int SCV;
	SCVState state;
	cin >> SCV;
	for (int i = 0; i < SCV; i++){
		cin >> state.scv[i];
	}

	BFS(state);
	cout << SCVStateMap[0][0][0] << '\n';
	return 0;
}

void BFS(SCVState start) {
	queue<SCVState> nearState;
	SCVStateMap[start.scv[0]][start.scv[1]][start.scv[2]] = 0;
	nearState.push(start);

	//탐색 시작
	while (!nearState.empty()) {
		SCVState curState = nearState.front();
		nearState.pop();

		//SCV 상태 확인
		if (curState.scv[0] == 0 && curState.scv[1] == 0  &&curState.scv[2] == 0) {
			break;
		}

		//SCV 공격 하기
		for (int a = 0; a < 6; a++){
			SCVState nextState;
			//SCV 상태 확인
			for (int b = 0; b < 3; b++){
				int remainHP = curState.scv[b] - Damage[a][b];
				nextState.scv[b] = remainHP < 0 ? 0 : remainHP;
			}
			//공격 횟수 저장 
			if (SCVStateMap[nextState.scv[0]][nextState.scv[1]][nextState.scv[2]] == -1) {
				nearState.push(nextState);
				SCVStateMap[nextState.scv[0]][nextState.scv[1]][nextState.scv[2]] = SCVStateMap[curState.scv[0]][curState.scv[1]][curState.scv[2]] + 1;
			}
		}
	}
}