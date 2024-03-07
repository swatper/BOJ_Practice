#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Students;
	//같은 학생의 중복 계산을 방지하기 위한 bool 변수
	bool Compaired = false;
	// 전체 학생 중에서 같은 반이었던 학생의 Index를 저장할 변수
	int Leader_Num = 0;
	//학생들의 정보를 저장할 2차원 배열
	int Grade_Class[1001][5];
	//학생 수 입력 받기
	cin >> Students;
	//학생별 같은 반이 된 학생들의 수를 저장할 배열을 동적 할당
	int* Mate_Times = new int[Students];
	//배열 초기화
	for (int i = 0; i < Students; i++) {
		Mate_Times[i] = 0;
	}
	//학생들의 학년별 반 입력받기
	for (int a = 0; a < Students; a++) {
		for (int b = 0; b < 5; b++) {
			cin >> Grade_Class[a][b];
		}
	}
	//a번째 학생의 기준으로 다른 학생들을 비교
	for (int a = 0; a < Students; a++) {	//기준이 되는 학생
		for (int b = 0; b < Students; b++) {//비교할 다른 학생
			for (int c = 0; c < 5; c++) {	//반 비교
				//본인꺼 제외하고 비교
				if(a != b && Grade_Class[a][c] == Grade_Class[b][c]) {
					Mate_Times[a]++;
					break;
				}
			}
		}
	}
	// 전체 학생 중에서 같은 반이었던 학생 수가 제일 많은 학생 찾기
	int Big_Num = Mate_Times[0];
	for (int i = 1; i < Students; i++) {
		if (Mate_Times[i] > Big_Num ) {
			Big_Num = Mate_Times[i];
			Leader_Num = i;
		}
	}
	cout << Leader_Num + 1 << "\n";
}