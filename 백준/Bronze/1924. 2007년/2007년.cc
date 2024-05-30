#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    //요일
    string Weeks[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    //월별 날짜 수
    int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int Month, Day, Week,TotalDays = 0;
    cin >> Month>> Day;
    for (int i = 0; i < (Month-1); i++){
        //해달 달의 날짜 와
        //(입력받은 달 -1)월까지 지난 달들의 일수를 모두 더함
        TotalDays += Months[i];
    }
    //요일 계산
    Week = (Day + TotalDays) % 7 ;
    cout << Weeks[Week] + "\n";
}