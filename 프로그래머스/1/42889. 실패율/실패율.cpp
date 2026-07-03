#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool Compare(pair<double, int> a, pair<double, int> b) {
    //실패율이 같으면 스테이지 우선
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int totalPeople = stages.size();
    vector<pair<double, int>> stageFailure;
    map<int, int> stageStatus;
    //스테이지 도달 상태 확인
    for (int person = 0; person < totalPeople; person++)
        stageStatus[stages[person]]++;
    //각 스테이지 실패율 계산
    for (int stage = 1; stage <= N; stage++) {
        //특정 스테이지에 도달한 사람이 없으면 실패율: 0
        if (stageStatus.find(stage) == stageStatus.end() || totalPeople == 0)
            stageFailure.push_back({ 0, stage });
        //각 스테이지 실패율 계산
        else {
            double failureRate =(double) stageStatus[stage] / totalPeople;
            stageFailure.push_back({ failureRate, stage });
            totalPeople -= stageStatus[stage];
        }
    }
    //내림차순 정렬
    sort(stageFailure.begin(), stageFailure.end(), Compare);
    for (int i = 0; i < N; i++)
        answer.push_back(stageFailure[i].second);
    return answer;
}