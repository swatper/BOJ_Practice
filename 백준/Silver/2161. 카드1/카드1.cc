#include <iostream>
#include <queue> //'큐'라는 자료 구조를 사용
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	queue<int> Deck;
	int Cards;
	cin >> Cards;
	//덱에 카드를 1부터 순서대로 저장
	for (int i = 1; i <= Cards; i++) {
		Deck.push(i);
	}

	while (true){
		//맨 위에 있는 카드 출력 및 제거
		int CardNum = Deck.front();
		cout << CardNum << " ";
		Deck.pop();
		//덱에 카드가 없으면 반복문 정지
		if (Deck.empty()) {
			break;
		}
		//카드가 남아 있으면 제일 위에 있는 카드를
		//임시로 저정하고 제거
		//다시 맨 아래에 저장
		CardNum = Deck.front();
		Deck.pop();
		Deck.push(CardNum);
	}
	cout << "\n";
	return 0;
}