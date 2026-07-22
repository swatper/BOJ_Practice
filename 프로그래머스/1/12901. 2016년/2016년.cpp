#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    //월별 일수 (2월은 윤년이므로 29일 설정)
    int monthDay[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //요일
    string day[8] = {"", "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    //계산하기
    int tmpDay = 0;
    for(int month = 1; month <= a; month++){
        //각 월별 일자 수 더하기
        if(month < a){
            tmpDay += monthDay[month];
        }
        //같은 월이면 남은 일자 수 더하기
        else{
            tmpDay += b;
        }
    }
    answer = day[(tmpDay - 1) % 7 + 1];
    return answer;
}