#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Num1, Num2, Num3, Total = 0;
	cin >> Num1 >> Num2 >> Num3;
	//같은 눈 3개일 경우
	if (Num1 == Num2 && Num2 == Num3){
		Total += 10000 + Num1 * 1000;
	}
	//같은 눈 2개일 경우
	else if(Num1 == Num2 || Num2 == Num3 || Num3 == Num1){
		if (Num1 == Num2){
			Total += 1000 + Num1 * 100;
		}
		else if (Num2 == Num3){
			Total += 1000 + Num2 * 100;
		}
		else{
			Total += 1000 + Num3 * 100;
		}
	}
	//모두 다른 눈일 걍우
	else{
		//가장 큰 눈 찾기 
		int MaxNum = max(Num1, max(Num2, Num3));
		Total += MaxNum * 100;
	}
	cout << Total << "\n";
	return 0;
}