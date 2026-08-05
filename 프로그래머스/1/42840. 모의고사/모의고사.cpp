#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //수포자들 답 찍는 패턴
    vector<vector<int>> supoAnswerPattern = { 
        {1, 2, 3, 4, 5}, 
        {2, 1, 2, 3, 2, 4, 2, 5}, 
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    //수포자들 점수
    int soupScore[3] = {0,};
    int maxScore = 0;
    //점수 계산하기
    for (int correct = 0; correct < answers.size(); correct++) {
        //패턴 범위 조절을 위해 모듈러 연산 사용 (답지 인덱스 % 패턴 길이)
        for (int supo = 0; supo < 3; supo++) {
            soupScore[supo] += supoAnswerPattern[supo][correct % supoAnswerPattern[supo].size()] == answers[correct] ? 1 : 0;
            //고득점자 점수 확인
            maxScore = soupScore[supo] > maxScore ?  soupScore[supo] : maxScore;
        }
    }
    //결과 확인
    for (int supo = 0; supo < 3; supo++){
        if (soupScore[supo] == maxScore) {
            answer.push_back(supo + 1);
        }
    }
    return answer;
}