#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progressSchedules;
    int finDate, finProgress, preFinDate;

    for (int i = 0; i < progresses.size(); i++) {
        //각 프로세스별 배포 날짜 계산
        finDate = (100 - progresses[i]+ speeds[i] - 1) / speeds[i];
        progressSchedules.push(finDate);
    }

    while (!progressSchedules.empty()) {
        //가장 앞 프로세스의 배포 날짜
        preFinDate = progressSchedules.front();
        finProgress = 0;
        //가장 앞 프로세스의 배포 일자보다 작은면 동시 배포 가능 
        while (!progressSchedules.empty() && preFinDate >= progressSchedules.front()) {
            progressSchedules.pop();
            finProgress++;
        }
        answer.push_back(finProgress);
    }

    return answer;
}