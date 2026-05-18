#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string begin, vector<vector<string>>& tickets, vector<bool>& visited, int cnt, vector<string>& result) {
    //출발지 저장
    result.push_back(begin);
    //모든 티켓을 사용했으면 탐색 종료
    if (cnt == tickets.size())
        return true;

    //현재 공항에서 갈 수 있는 공항 찾기
    for (int i = 0; i < tickets.size(); i++) {
        //아직 방문 안 한 곳이면
        if (begin == tickets[i][0] && !visited[i]) {
            //티켓 사용
            visited[i] = true;
            //재귀(깊이 우선 탐색)
            if (DFS(tickets[i][1], tickets, visited, cnt + 1, result)) {
                return true;
            }
            //티켓 사용 취소
            visited[i] = false;
        }
    }
    //갈 수 있는 공항이 없으면(탐색 실패), 다른 도착지(티켓) 알아보기
        //["ICN", "A"], ["ICN", "B"], ["B", "ICN"] 인 경우, ["ICN", "B"]를 거처야 하지만,
        //로직 상 ["ICN", "A"]을 먼저 방문
        //-> 반복문 결과 모든 곳을 가지 않았으므로, 다른 티켓(["ICN", "B"])을 선택해야 됨
    result.pop_back();
    return false;
}

//출발지 기준 정렬
bool Compare(vector<string>& a, vector<string>b) {
    //출발지가 같으면 도착지 기준 정렬
    if (a[0] == b[0])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> usedTickets(tickets.size(), false);
    sort(tickets.begin(), tickets.end(), Compare);
    DFS("ICN", tickets, usedTickets, 0, answer);
    return answer;
}