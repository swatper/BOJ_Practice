#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	//월 이름
	string monthName[12] = { "January", "February","March", "April", "May" , "June",
						"July", "August", "September", "October", "November", "December" };
	//월별 일 수
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	double totlaTimes, percent, pastTimes = 0;
	//입력 받은 날짜를 저장할 변수
	string Month, Day, Year ,Time;
	int Hour , Min;
	cin >> Month >> Day >> Year >> Time;


	//윤년 확인: 400으로 나누어 떨어지거나, 4로 나누어 떨어지면서, 100으로 나누어 떨어지지 않는 해)
	if (stoi(Year) % 400 == 0 || (stoi(Year) % 4 == 0 && stoi(Year) % 100 != 0)) {
		//입력 받은 연도가 운년일 수 도 있으므로 배열의 값을 변경
		monthDays[1] = 29;
		//한 해의 전체 기간을 분으로 계산
		totlaTimes = 366 * 24 * 60;
	}
	else {
		//한 해의 전체 기간을 분으로 계산
		totlaTimes = 365 * 24 * 60;
	}
	//지나간 월들의 일 수를 계산
	for (int i = 0; i < 12; i++) {
		if (Month == monthName[i]) {
			break;
		}
		else {
		pastTimes += monthDays[i];
		}
	}
	//---------여기까지 계산하면 해당 달의 제외한 지난달의 일 수를 다 더한 상태

	//해당 월의 지나간 일 수를 계산
	//48로 나눈 이유는 string의 [n]번째는 char로 int로 변환시 아스키 코드값으로 반환 (0의 아스키코드값: 48)
	if (((int)Day[0]) % 48 == 0 && ((int)Day[1]) % 48 == 1) { //해당 일이 1일이면
		//일 수를 더할 필요 없음
	}
	else {
		//-1은 계산할 때 당일 제외
		pastTimes = pastTimes + ((int)Day[0]) % 48 * 10 + ((int)Day[1]) % 48 - 1;
	}
	//해당 일의 지나간 시간 계산
	Hour = ((int)Time[0]) % 48 * 10 + ((int)Time[1]) % 48;
	Min = ((int)Time[3]) % 48 * 10 + ((int)Time[4]) % 48;
	pastTimes = pastTimes * 24 * 60 + Hour * 60 + Min;
	//---------여기까지 계산하면 지나간 시간을 모두 분으로 계산한 상태
	
	//계산
	percent = pastTimes / totlaTimes * 100;
	cout.precision(12);
	cout << percent << "\n";
	return 0;
}