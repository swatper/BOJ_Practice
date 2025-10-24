#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int towers, curLength;
	stack<pair<int, int>> towerList; //{타워번호, 높이}
	cin >> towers;
	//수신 받을 수 있는 타워 번호를 저장할 배열
	vector<int> recTower(towers, 0); 
	for (int i = 1; i <= towers; i++){
		cin >> curLength;
		while (!towerList.empty()) {
			int preTowerLength = towerList.top().second;
			//현재 탑의 높이가 이전 탑의 높이보다 낮으면 수신 가능
			if (preTowerLength >= curLength) {
				recTower[i - 1] = towerList.top().first;
				//이후 탑 들은 수신할 수 없으니 무시
				break;
			}
			else {
				//현재 탑이 이전 탑보다 높으면 현재 탑 기준으로 이후 탑들 수신 못함
				//--> 이전 탑을 목록에서 제거
				towerList.pop();
			}
		}
		//이후 나올 타워랑 비교를 위해 저장
		towerList.push({i, curLength });
	}
	
	//결과 확인
	for (int i = 0; i < towers; i++){
		cout << recTower[i] << " ";
	}
	cout << "\n";
	return 0;
}