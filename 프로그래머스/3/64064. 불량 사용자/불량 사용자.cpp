#include <string>
#include <vector>
#include <set>

using namespace std;

bool CheckMatch(string& target, string& pattern) {
    bool isMatched = true;
    if (target.length() == pattern.length()) {
        for (int i = 0; i < target.length(); i++) {
            if (pattern[i] !=  '*' && target[i] != pattern[i]) {
                isMatched = false;
                break;
            }
        }
    }
    else
        isMatched = false;

    return isMatched;
}

//조합(벤ID-타켓ID)에 대한 전체 조합의 수
void DFS(int banIndex, vector<string>& user_id, vector<string>& banned_id,
    vector<bool>& visited,
    set<string>& combin, set<set<string>>& allCombin) {
    if (banIndex >= banned_id.size()) {
        allCombin.insert(combin);
        return;
    }

    //깊이 우선 탐색
    for (int t = 0; t < user_id.size(); t++) {
        if (!visited[t] && CheckMatch(user_id[t], banned_id[banIndex])) {
            visited[t] = true;
            combin.insert(user_id[t]);

            //재귀
            DFS(banIndex + 1, user_id, banned_id, visited, combin, allCombin);

            //탐색 종료: 초기화
            combin.erase(user_id[t]);
            visited[t] = false;
        }

    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> visited(8, false);
    set<set<string>> allCombin;
    set<string> combin;
    DFS(0, user_id, banned_id, visited, combin, allCombin);
    return allCombin.size();
}