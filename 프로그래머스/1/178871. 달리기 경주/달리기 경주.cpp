#include <string>
#include <vector>
#include <unordered_map> //Hash map O(1)

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerRanking;
    //초기 선수 순위 설정
    for (int p = 0; p < players.size(); p++) {
        playerRanking[players[p]] = p;
    }
    //추월 시작
    for (int i = 0; i < callings.size(); i++) {
        //호출 선수 찾기
        int passPlayer = playerRanking[callings[i]];
        //순위 조정하기
        playerRanking[players[passPlayer]]--; //순위 올리기
        playerRanking[players[passPlayer - 1]]++; //순위 내리기
        //순위 이름 조정
        string tmp = players[passPlayer];
        players[passPlayer] = players[passPlayer - 1];
        players[passPlayer - 1] = tmp;

    }
    return players;
}