#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Milk, Milks, DrinkMilks = 0;
	//현재 마실 수 있는 우유 0: 딸기 1: 초고 2: 바나나
	int CurrentMilk = 0;
	cin >> Milks;
	for (int i = 0; i < Milks; i++){
		cin >> Milk;
		if(CurrentMilk == Milk){
			//현재 마실수 있는 우유와
			//가게에서 파는 우유가 같으면
			//현재 마실 수 있는 우유의 숫자를 늘림
			CurrentMilk++;
			//우류를 마신 횟수 증가
			DrinkMilks++;
			if (CurrentMilk >= 3){
				//3이상이면 다시 0으로 만들어
				//딸기 우유를 마시도록 함
				CurrentMilk = 0;
			}
		}
	}
	cout << DrinkMilks << "\n";
	return 0;
}