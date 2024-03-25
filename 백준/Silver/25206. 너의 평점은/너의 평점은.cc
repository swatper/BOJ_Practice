#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	double Grade, TotalGrade = 0,TotalScore = 0;
	double GPA = 0;
	string Subject , Score;
	for (int i = 0; i < 20; i++) {
		cin >> Subject >> Grade >> Score;
		//학점 점수 계산
		if (Score == "A+") { TotalScore += Grade * 4.5; }
		if (Score == "A0") { TotalScore += Grade * 4.0; }
		if (Score == "B+") { TotalScore += Grade * 3.5; }
		if (Score == "B0") { TotalScore += Grade * 3.0; }
		if (Score == "C+") { TotalScore += Grade * 2.5; }
		if (Score == "C0") { TotalScore += Grade * 2.0; }
		if (Score == "D+") { TotalScore += Grade * 1.5; }
		if (Score == "D0") { TotalScore += Grade * 1.0; }
		if (Score == "F") { TotalScore += Grade * 0; }
		if (Score == "P") { Grade = 0.0; }
		//전체 학점 계산
		TotalGrade += Grade;
	}
	//전체 전공 평점 계산
	GPA = TotalScore / TotalGrade;
	//소수점 자릿수 고정
	cout << fixed;
	cout.precision(6);
	cout << GPA << "\n";

	return 0;
}