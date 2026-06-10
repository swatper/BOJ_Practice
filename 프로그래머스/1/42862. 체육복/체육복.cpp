#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //각 학생별 체육복 보유 개수
    vector<int> studentsClothes(n, 1);
    //여벌 있는 학생 확인
    for (int student = 0; student < reserve.size(); student++)
        studentsClothes[reserve[student] - 1]++;
    //도난 당한 학생 확인
    for (int student = 0; student < lost.size(); student++)
        studentsClothes[lost[student] - 1]--;
    //체육복 빌려주기
    for (int student = 0; student < n; student++) {
        if(studentsClothes[student] == 0){
            //이전 학생꺼 빌리기
            if(student > 0 && studentsClothes[student - 1] > 1){
                studentsClothes[student]++;
                studentsClothes[student - 1]--;
            }
            //다음 학생꺼 빌리기
            else if(student < n - 1 && studentsClothes[student + 1] > 1){
                studentsClothes[student]++;
                studentsClothes[student + 1]--;
            }
        }
    }

    //결과 확인
    for (int student = 0; student < n; student++)
        answer+= studentsClothes[student] >= 1;
    
    return answer;
}