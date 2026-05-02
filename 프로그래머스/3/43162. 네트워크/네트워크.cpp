#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(computers.size(), false);
    for(int i = 0; i < computers.size(); i++){
        if(visited[i])
            continue;
        //너비 우선 탐색
        queue<int> nxtCom;
        nxtCom.push(i);
        answer++;
        visited[i] = true;
        //탐색시작
        while(!nxtCom.empty()){
            int curCom = nxtCom.front();
            nxtCom.pop();
            //연결된 컴퓨터 찾기
            for(int next = 0; next < computers[curCom].size(); next++){
                if(computers[curCom][next] == 1 && !visited[next]){
                    visited[next] = true;
                    nxtCom.push(next);
                }
            }
        }
    }
    return answer;
}