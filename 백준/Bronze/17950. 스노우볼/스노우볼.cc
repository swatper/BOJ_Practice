#include <iostream>
//제곱 함수 pow()를 사용하기 위하 math.h 헤더파일 가져옴
#include <math.h>
using namespace std;
#define MAX 1000000007 //문제에서 값의 크기를 10^9+7로 나눈 나머지로 제한

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//크기의 합을 저장할 변수
	unsigned long addTotalSize = 0;
	double H, X, Ci;
	unsigned long Ci_Size = 1;
	//높이랑 커지는 크기 입력받기
	cin >> H >> X;
	//크기^높이 * 개수
	for (int a = 1; a <= H; a++) {
		//눈덩이 계수 입력받기
		cin >> Ci;
		Ci_Size *= X ;
		Ci_Size %= MAX;
		addTotalSize += Ci_Size * Ci;
		addTotalSize %= MAX;
	}
	cout << addTotalSize << "\n";
	return 0;
}