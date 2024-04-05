#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ReqExTime, LowPulse, HighPulse, IncreasePulse, DecreasePulse;
	int CurrentPulse, Extime = 0, TotalTime = 0;
	cin >> ReqExTime >> LowPulse >> HighPulse >> IncreasePulse >> DecreasePulse;
	CurrentPulse = LowPulse;
	while (ReqExTime > Extime){
		//계산 불가능
		if (HighPulse - LowPulse < IncreasePulse) {
			TotalTime = -1;
			break;
		}
		//운동할 수 있을 때
		if (CurrentPulse + IncreasePulse <= HighPulse) {
			TotalTime++;
			Extime++;
			CurrentPulse += IncreasePulse;
		}
		//운동할 수 없을 때
		else if (CurrentPulse + IncreasePulse > HighPulse) {
			TotalTime++;
			CurrentPulse -= DecreasePulse;
			if (CurrentPulse < LowPulse) {
				CurrentPulse = LowPulse;
			}
		}
	}
	cout << TotalTime << "\n";
	return 0;
}