#include <iostream>
using namespace std;

//낱개를 패키지로 샀을때와 낱개로 샀을때의 가격을 비교하는 함수
int Price_Compair(int N,int pack, int item) {
	int tmp1, tmp2;
	//낱개를 패키지로 샀을때의 가격
	if (N % 6 == 0) {
		tmp1 = (N / 6) * pack;
	}
	else {
		tmp1 = ((N / 6) + 1) * pack;
	}
	//낱개를 낱개로 샀을때의 가격
	if (pack >= (item * 6)) {//패키지 가격이 낱개 6개 가격보다 낮으면
		//모두 낱개로 삼
		tmp2 = N * item;
	}
	else {
		tmp2 = (N / 6) * pack + (N % 6) * item;
	}
	//가격 비교
	if (tmp1 <= tmp2) {
		return tmp1;
	}
	else {
		return tmp2;
	}
}

int main() {
	//필요한 줄의 수, 브랜드의 수
	int N, M;
	//소비 가격
	int price;
	cin >> N >> M;
	//가장 낮은 패키지 가격과 낱개의 가격을 저장할 변수
	int Pack_price, Item_price;

	//브랜드의 수 만큼 반복
	for (int i = 0; i < M; i++) {
		int Brand_Pack, Brand_item;
		//각 브랜드의 패키지 가격과 낱개 가격을 입력 받기
		cin >> Brand_Pack >> Brand_item;
		//첫 브랜드의 패키지 가격과 낱개 가격을 입력 받기
		if (i == 0) {
			Pack_price = Brand_Pack;
			Item_price = Brand_item;
		}
		//각 브랜드의 패키지 가격을 비교하여 가장 낮은 가격을 저장
		if (Pack_price > Brand_Pack) {
			Pack_price = Brand_Pack;
		}
		//각 브랜드의 낱개 가격을 비교하여 가장 낮은 가격을 저장
		if (Item_price > Brand_item) {
			Item_price = Brand_item;
		}
	}
	//최저가를 입력받고 낱개를 패키지로 가는게 저렴한지 낱개로 사는게 저렴한지 비교
	price = Price_Compair(N, Pack_price, Item_price);
	cout << price << "\n";
	return 0;
}