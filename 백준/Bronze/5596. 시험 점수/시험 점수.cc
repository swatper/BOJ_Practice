#include <iostream>
using namespace std;

//총점 계산
int TotalScoreCal(int StudentScore) {
	int TotalScore;
	for (int i = 0; i < 4; i++) {
		cin >> TotalScore;
		StudentScore += TotalScore;
	}
	return StudentScore;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int MGScore = 0, MSScore = 0, HighestScore = 0;
	MGScore = TotalScoreCal(MGScore);
	MSScore = TotalScoreCal(MSScore);
	//가장 높은 점수 구하기(삼항연산)
	HighestScore = MGScore > MSScore ? MGScore : MSScore;
	cout << HighestScore << "\n";
}