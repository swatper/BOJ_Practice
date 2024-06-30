#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, Max_Happiness;
	cin >> N >> M;
	//동적 배열 생성
	int* CodeLength = new int[N];
	//원소 입력 받기
	for (int i = 0; i < N; i++) {
		cin >> CodeLength[i];
	}
	//행복도 계산 방법을 보면 (i+1)번째 - (i)번째의 전체 합이므로
	//수열의 (맨 뒤 - 맨 앞)만 계산하면 행복도를 구할 수 있음
	int Front_Index = 0, Back_Index = N - M - 1;
	int Front_Min = CodeLength[Front_Index];
	//맨 뒤에서 M개 지웠을 때의 결과 저장
	Max_Happiness = CodeLength[Back_Index] - Front_Min;
	while (Back_Index < N){
		//앞에서 지움 (삼항연산)
		Front_Min = (Front_Min < CodeLength[Front_Index]) ? Front_Min : CodeLength[Front_Index];
		Max_Happiness = (Max_Happiness > (CodeLength[Back_Index] - Front_Min)) ? Max_Happiness : (CodeLength[Back_Index] - Front_Min);
		//전체적으로 이동
		Front_Index++;
		Back_Index++;
	}
	cout << Max_Happiness << "\n";
	return 0;
}
//참고: https://github.com/infikei/algorithm/blob/main/baekjoon_all/29000%2B/boj_29726_contest75_N_NP.cpp