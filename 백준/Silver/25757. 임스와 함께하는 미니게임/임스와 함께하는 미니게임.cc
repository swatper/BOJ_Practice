#include <iostream>
#include <map>
using namespace std;

//매핑 연습
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int playersRequest, reqPlayers, count = 0, play = 0;
	char gameType;
	cin >> playersRequest >> gameType;
	map<string, bool> playerList;

	//게임 종류 확인하고 필요한 플레이어 수 설정(본인 제외)
	switch (gameType){
	case 'Y':
		reqPlayers = 1;
		break;
	case 'F':
		reqPlayers = 2;
		break;
	case 'O':
		reqPlayers = 3;
		break;
	}

	for (int i = 0; i < playersRequest; i++){
		string playerName;
		cin >> playerName;
		//입력 받은 플레이어가 플레이어 목록에 있는지 확인
		if (playerList.find(playerName) != playerList.end()) {
			continue;
		}
		//없으면 플레이어 목록에 추가
		else {
			playerList.insert({playerName, true});
			//같이 게임할 사람 수 증가
			count++;
		}

		if (count == reqPlayers){
			//게임 진행
			play++;
			//같이 게임할 사람 수 초기화
			count = 0;
		}
	}
	cout << play << "\n";
	return 0;
}    