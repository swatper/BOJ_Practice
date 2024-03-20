#include <iostream>
#include <cmath>
using namespace std;
/*
	두 터렛의 정보를 이용하여 원을 그림
	그 원을 이용하여 교점의 갯수를 구하면
	마린이 존재할 수 있는 위치를 구할 수 있음
*/
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int joPosX, joPosY,joPosR;   //조규현의 X , Y , 거리
	int baekPosX, baekPosY, baekPosR; //백승환의 X , Y , 거리
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++) {
		int Exist = 0;
		//좌표와 거리 입력받기
		cin >> joPosX >> joPosY >> joPosR >> baekPosX >> baekPosY >> baekPosR;
		//sqrt(): 제곱근, Pow(): 제곱, abs(): 절댓값
		double distance = sqrt(pow(joPosX - baekPosX, 2) + pow(joPosY - baekPosY, 2));

		//두 원이 서로 같음
		if (distance == 0 && joPosR == baekPosR) {
			Exist = -1;
		}
		//두 원이 서로 외접하거나 내접하는 경우
		else if (distance == (joPosR + baekPosR) || distance == abs(joPosR - baekPosR)) {
			Exist = 1;
		}
		//두 원 사이의 거리보다 두 원의 반경이 클 경우 서로 교점이 2개 발생
		else if (distance < (joPosR + baekPosR) && distance > abs(joPosR - baekPosR)) {
			Exist = 2;
		}
		//두 원의 거리가 멀거나 안에 있는 경우
		else {
			Exist = 0;
		}
		cout << Exist << "\n";
	}
	return 0;
}