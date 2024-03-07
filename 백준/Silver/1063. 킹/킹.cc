#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string King, Stone, Move;
	int Try;
	cin >> King >> Stone >> Try;
	char KingX = King[0], KingY = King[1], StoneX = Stone[0], StoneY = Stone[1];
	for (int i = 0; i < Try; i++) {
		cin >> Move;
		//킹 이동시키기
		if (Move == "R") {
			if (KingX >= 65 && KingX < 72) { //범위 확인
				KingX++; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX >= 65 && StoneX< 72) { //범위 확인
					StoneX++;
				}
				else {
					KingX--; //다시 돌아가기
				}
			}
		}
		else if(Move == "L") {
			if (KingX > 65 && KingX <= 72) { //범위 확인
				KingX--; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX > 65 && StoneX <= 72) { //범위 확인
					StoneX--;
				}
				else {
					KingX++; //다시 돌아가기
				}
			}
		}
		else if (Move == "B") {
			if (KingY >49 && KingY<=56) { //범위 확인
				KingY--; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneY > 49 && StoneY <= 56) { //범위 확인
					StoneY--;
				}
				else {
					KingY++; //다시 돌아가기
				}
			}
		}
		else if (Move == "T") {
			if (KingY >= 49 && KingY < 56) { //범위 확인
				KingY++; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneY >= 49 && StoneY < 56) { //범위 확인
					StoneY++;
				}
				else {
					KingY--; //다시 돌아가기
				}
			}
		}
		else if (Move == "RT") {
			if (KingX >= 65 && KingX < 72 && KingY >= 49 && KingY < 56) { //범위 확인
				KingX++; //킹 이동
				KingY++; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX >= 65 && StoneX < 72 && StoneY >= 49 && StoneY < 56) { //범위 확인
					StoneX++;
					StoneY++;
				}
				else {
					KingX--; //다시 돌아가기
					KingY--; //다시 돌아가기
				}
			}
		}
		else if (Move == "LT") {
			if (KingX > 65 && KingX <= 72 && KingY >= 49 && KingY < 56) { //범위 확인
				KingX--; //킹 이동
				KingY++; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX > 65 && StoneX <= 72 && StoneY >= 49 && StoneY < 56) { //범위 확인
					StoneX--;
					StoneY++;
				}
				else {
					KingX++; //다시 돌아가기
					KingY--; //다시 돌아가기
				}
			}
		}
		else if (Move == "RB") {
			if (KingX >= 65 && KingX < 72 && KingY >49 && KingY <= 56) { //범위 확인
				KingX++; //킹 이동
				KingY--; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX >= 65 && StoneX < 72 && StoneY > 49 && StoneY <= 56) { //범위 확인
					StoneX++;
					StoneY--;
				}
				else {
					KingX--; //다시 돌아가기
					KingY++; //다시 돌아가기
				}
			}
		}
		else if (Move == "LB") {
			if (KingX > 65 && KingX <= 72 && KingY > 49 && KingY <= 56) { //범위 확인
				KingX--; //킹 이동
				KingY--; //킹 이동
			}
			if (KingX == StoneX && KingY == StoneY) {//돌이랑 충돌 확인
				if (StoneX > 65 && StoneX <= 72 && StoneY > 49 && StoneY <= 56) { //범위 확인
					StoneX--;
					StoneY--;
				}
				else {
					KingX++; //다시 돌아가기
					KingY++; //다시 돌아가기
				}
			}
		}
	}
	cout << KingX <<KingY << "\n" << StoneX << StoneY << "\n";
	return 0;
}