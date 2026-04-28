#include <iostream>
#include <queue>

using namespace std;

struct State {
    int t;                  //현재 시간
    int cups;           //빈 잔 개수
    int coffee;        //담긴 커피 개수
    int serveIdx;    //도착한(서빙할) 손님 index
    int makeIdx;    //도착 예정 손님 index
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int customers, meltTime;
    cin >> customers >> meltTime;
    int* arriveTime = new int[customers];
    for (int i = 0; i < customers; i++) {
        cin >> arriveTime[i];
    }

    bool isPossible = false;
    queue<State> q;
    //초기 상태: 0초, 잔 0, 커피 0, 서빙 0, 제조 0
    q.push({ 0, 0, 0, 0, 0 });
    //너비 우선 탐색
    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        //모든 손님 서빙 완료 시 성공
        if (cur.serveIdx == customers) {
            isPossible = true;
            break;
        }

        //마지막 손님 시간을 넘겼는데 서빙을 못 끝냈다면 해당 경로는 실패 (다음 경로 확인)
        if (cur.t > arriveTime[customers - 1])
            continue;

        //서빙하기: 손님 도착 확인
        if (cur.t == arriveTime[cur.serveIdx]) {
            if (cur.coffee > 0) {
                q.push({ cur.t + 1, cur.cups, cur.coffee - 1, cur.serveIdx + 1, cur.makeIdx });
            }
            continue;
        }
        //커피 내리기: 다음 올 손님 도착 및 컵 녹는 시간 확인
        else if (cur.makeIdx < customers && cur.cups > 0 && arriveTime[cur.makeIdx] <= cur.t + meltTime) {
            q.push({ cur.t + 1, cur.cups - 1, cur.coffee + 1, cur.serveIdx, cur.makeIdx + 1 });
        }
        //커피 잔 만들기
        else
            q.push({ cur.t + 1, cur.cups + 1, cur.coffee, cur.serveIdx, cur.makeIdx });
    }

    if (isPossible)
        cout << "success" << '\n';
    else
        cout << "fail" << '\n';

    return 0;
}