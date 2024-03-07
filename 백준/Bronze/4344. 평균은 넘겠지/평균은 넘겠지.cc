#include <iostream>
using namespace std;

int main() {
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++) {
		double avg = 0;	//평균
		int Students;	//학생수
		double Pc;	//평균을 넘는 학생의 비율
		int S = 0;		//평균을 넘는 학생의 수
		cin >> Students;
		int* Score = new int[Students]; //학생들 성적 배열
		for (int a = 0; a < Students; a++) {
			cin >> Score[a]; //학생들 성적 입력
			avg += Score[a];
		}
		avg = avg / (double)Students; //평균 계산
		for (int i = 0; i < Students; i++) {
			if (Score[i] > avg) {		//평균을 넘는 학생 수 구하기
				S++;
			}
		}
		Pc = ((double)S / (double)Students) * 100;
		cout << fixed; //고정
		cout.precision(3); //소수점 셋째자리에서 반올림
		cout << Pc << "%" << endl;
	}
}