#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> longestTasks;

    for (int i = 0; i < works.size(); i++)
        longestTasks.push(works[i]);

    for (int i = 0; i < n; i++) {
        if (longestTasks.empty())
            break;
        int longestTask = longestTasks.top() - 1;
        longestTasks.pop();
        if (longestTask > 0)
            longestTasks.push(longestTask);
    }

    while (!longestTasks.empty()) {
        int task = longestTasks.top();
        answer += task * task;
        longestTasks.pop();
    }
        
    return answer;
}