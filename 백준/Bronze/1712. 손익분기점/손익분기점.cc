#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//처음에는 반복문을 통해 손익분기점을 계산하려 하였으나,
	//시간초과를 고려하여 다른 계산방법을 선택함

	int Cost1, Cost2, Price, Point = 1;
	cin >> Cost1 >> Cost2 >> Price;
	//생산 비용과 가격을 비교하여 손익분기점이 존재하는지 확인
	if (Cost2 >= Price) {
		Point = -1;
	}
	else {
		//손익분기점 계산하기(전체비용 / 한 대당 판매 수익)
		Point = (Cost1/(Price - Cost2)) + 1;
	}
	cout << Point << "\n";
	return 0;
}