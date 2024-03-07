#include <iostream>
#include <string>
using namespace std;

int WinTime(string PastTime, string GoalTime) {
	int PastM , GoalM, Time = 0;
	PastM = ((((int)PastTime[0]) % 48) * 10 + ((int)PastTime[1]) % 48) * 60 + (((int)PastTime[3]) % 48) * 10 + ((int)PastTime[4]) % 48;
	GoalM = ((((int)GoalTime[0]) % 48) * 10 + ((int)GoalTime[1]) % 48) * 60 + (((int)GoalTime[3]) % 48) * 10 + ((int)GoalTime[4]) % 48;
	//cout << GoalM << " " << PastM << "\n";
	Time = GoalM - PastM;
	return Time;
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Goals, GoalTeam, T1Time = 0, T2Time = 0, T1 = 0, T2 = 0;
	string GoalTime, PastTime = "00:00";
	cin >> Goals;
	for (int i = 0; i <= Goals; i++) {
		GoalTeam = 0;
		if (i < Goals) {
			cin >> GoalTeam >> GoalTime;
		}
		//팀 점수를 비교하여 이기고 있는 팀 시간 계산하기
		if (i > 0) {
			if (i == Goals) {
				GoalTime = "48:00";
			}
			if (T1 > T2) {
				T1Time += WinTime(PastTime, GoalTime);
			}
			else if (T1 < T2) {
				T2Time += WinTime(PastTime, GoalTime);
			}
		}
		//팀 확인하고 팀 점수 올리기
		if (GoalTeam == 1) {
			T1++;
		}
		else if (GoalTeam == 2){
			T2++;
		}
		
		PastTime = GoalTime;
	}
	string MM, SS;
	MM = to_string(T1Time / 60);
	if (MM.size() < 2) {
		MM = "0" + MM;
	}
	SS = to_string(T1Time % 60);
	if (SS.size() < 2) {
		SS = "0" + SS;
	}
	cout << MM<< ":" << SS << "\n";
	MM = to_string(T2Time / 60);
	if (MM.size() < 2) {
		MM = "0" + MM;
	}
	SS = to_string(T2Time % 60);
	if (SS.size() < 2) {
		SS = "0" + SS;
	}
	cout << MM << ":" << SS<< "\n";
	return 0;
}