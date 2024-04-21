#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Cards;
	cin >> Cards;
	deque<int> Deck;
	int* Command = new int[Cards];
	for (int i = 0; i < Cards; i++){
		cin >> Command[i];
	}
	int Temp, Card = 1;
	//연산 과정을 역으로 하여 초기 상태를 찾음
	for (int i = Cards - 1; i >= 0; i--) {
		switch (Command[i]){
		//카드가 맨 아래에 있었으므로 맨 위에 카드 추가
		case 1:
			Deck.push_front(Card);
			break;
		//카드가 아래에서 두 번째에 있었므로, 맨 위에서 두 번째에 카드 추가
		case 2:
			Temp = Deck.front();
			Deck.pop_front();
			Deck.push_front(Card);
			Deck.push_front(Temp);
			break;
		//카드가 맨 위에 있었으므로 맨 아래에 카드 추가
		case 3:
			Deck.push_back(Card);
			break;
		}
		Card++;
	}
	for (int i = 0; i < Cards; i++) {
		cout << Deck[i] << " ";
	}
	cout << "\n";
	return 0;
}