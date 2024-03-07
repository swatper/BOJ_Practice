#include <iostream>
using namespace std;
//후보의 정보를 저장할 클래스
class Candidate {
public:
	//3점,2점,1점의 개수를 저장할 변수들
	int Score_3 = 0;
	int Score_2 = 0;
	int Score_1 = 0;
	//후보의 합산 점수를 저장할 변수
	int totalScore = 0;
	//후보의 번호를 저장할 변수
	int Candidate_Num;
	//점수 계산
	void Cal(int n) {
		if (n == 3) {
			Score_3++;
		}
		else if(n == 2){
			Score_2++;
		}
		else {
			Score_1++;
		}
		totalScore += n;
	}
};
//후보들 비교 함수
Candidate Compair(Candidate A, Candidate B) {
	if (A.totalScore> B.totalScore) {
		return A;
	}
	else if (A.totalScore == B.totalScore) { //합산 점수가 같을 경우

		if (A.Score_3 > B.Score_3) { //3점 개수 비교
			return A;
		}
		else if (A.Score_3 == B.Score_3){ //3점의 개수가 같을 경우

			if (A.Score_2> B.Score_3) { //2점의 개수 비교
				return A;
			}
			else if (A.Score_2 == B.Score_2) {// 2점의 개수도 같음 -> 회장 못 뽑음
				A.Candidate_Num = 0;
				return A;
			}
			else {
				return B;
			}

		}
		else {
			return B;
		}

	}
	else {
		return B;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//후보들을 저장할 객체 배열
	Candidate Candidates[4];
	for (int i = 1; i < 4; i++) {
		Candidates[i].Candidate_Num = i;
	}
	int N;
	cin >> N;
	//각 후보들의 점수 계산
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >>  b >> c;
		Candidates[1].Cal(a);
		Candidates[2].Cal(b);
		Candidates[3].Cal(c);
	}
	//각 후보들의 비교
	Candidates[0] = Compair(Candidates[1],Candidates[2]);
	Candidates[0] = Compair(Candidates[0], Candidates[3]);
	cout << Candidates[0].Candidate_Num <<  " " << Candidates[0].totalScore<< "\n";
	return 0;
}
