#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Num, NewNum;
	int Count = 0;
	cin >> Num;
	NewNum = Num;
	//사이클
	while (true) {
		//맨 처음 주어진 값이 10보다 큰지 작은지 확인
		if (Num.size() == 1 && Count == 0) {
			Num = "0" + Num;
			NewNum = Num;
			continue;
		}
		else {
			int Tmp = (stoi(NewNum) / 10 + stoi(NewNum) % 10) % 10;
;			NewNum = NewNum[1] + to_string(Tmp);
		}
		Count++;
		//사이클 결과가 처음 값과 같은지 확인
		if (Num == NewNum) {
			break;
		}
	}
	cout << Count << "\n";
	return 0;
}