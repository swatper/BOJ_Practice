#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int numbersSize = numbers.size() - 1;
    //너비 우선 탐색 (현재 값, 항 인덱스)
    queue<pair<int, int>> cases;
    //탐색 시작
    cases.push({numbers[0], 0});
    cases.push({-numbers[0], 0});
    while (!cases.empty()) {
        int curResult = cases.front().first;
        int curTerm = cases.front().second;
        cases.pop();
        //모든 항을 계산 했는지 확인 (최종 결과)
        if (curTerm == numbersSize) {
            if (curResult == target)
                answer++;
        }
        else {
            //다음 항으로 이동
            curTerm++;
            //다음 항을 더하는 경우와 빼는 경우를 넣음
            cases.push({curResult + numbers[curTerm], curTerm});
            cases.push({curResult - numbers[curTerm], curTerm});
        }
    }
    return answer;
}