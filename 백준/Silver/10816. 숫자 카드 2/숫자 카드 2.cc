#include <iostream>
#include <algorithm> //sorting 알고리즘을 사용하기 위함
using namespace std;

//숫자가 시작되는 처음 인덱스 구하기
int FrontIndex(int CardsArray[], int FindCardNum, int Cards) {
	int Low = 0;
	int High = Cards;
	int Index = 0;
	//이분 탐색
	while (Low <= High) {
		int Mid = (Low + High) / 2;
		if (CardsArray[Mid] < FindCardNum) {
			Low = Mid + 1;
		}
		else {
			High = Mid - 1;
			Index = Mid;
		}
	}
	if (CardsArray[Index] != FindCardNum) {//찿는 카드가 없으면
		Index = 1;
	}
	return Index;
};
//숫자가 끝나는 마지막 인덱스 찾기
int BackIndex(int CardsArray[], int FindCardNum, int Cards) {
	int Low = 0;
	int High = Cards;
	int Index = 0;
	//이분 탐색
	while (Low <= High) {
		int Mid = (Low + High) / 2;
		if (CardsArray[Mid] <= FindCardNum) {
			Index = Mid;
			Low = Mid + 1;
		}
		else {
			High = Mid - 1;
		}
	}
	if (CardsArray[Index] != FindCardNum) {//찿는 카드가 없으면
		Index = -1;
	}
	return Index;
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int Cards;
	cin >> Cards;
	int* CardsArray = new int[Cards];
	for (int i = 0; i < Cards; i++) { 
		//처음 카드 입력받기
		cin >> CardsArray[i];
	}
	//입력 받은 카드들을 오름차순으로 정렬
	sort(CardsArray, CardsArray + Cards);

	int FindCards;
	cin >> FindCards;
	int FindCard;
	for (int i = 0; i < FindCards; i++) {
		//찾을 카드 입력 받기
		cin >> FindCard;
		//카드 찾기
		int Result = BackIndex(CardsArray, FindCard, Cards - 1) - FrontIndex(CardsArray, FindCard, Cards - 1);
		if (Result < 0) {//카드 없음
			Result = 0;
		}
		else if (Result == 0){ //카드 한 장 있음
			Result = 1;
		}
		else {//카드 여러 장 있음
			Result += 1;
		}
		cout << Result << " ";
	}
	cout << "\n";
	delete[] CardsArray;
	return 0;
}
