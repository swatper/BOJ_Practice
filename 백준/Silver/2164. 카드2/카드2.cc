#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	//맨 앞의 카드가 제가되고 뒤에 숫자가 입력되므로 큐를 사용

	queue<int> Cards;		//큐 생성
	for (int i = 1; i <= N; i++) {
		Cards.push(i);		//큐에 숫자를 입력
	}

	while (Cards.size() > 1) {			//큐에 값이 하나만 남을 때까지 반복
		Cards.pop();					//큐에 있는 값들 중 맨 앞에 있는 값을 제거
		int a = Cards.front();			//카드 제거후 맨 앞에 있는 값 가져오기
		Cards.push(a);					//가져온 값을 큐에 입력(맨 뒤로 이동)
		Cards.pop();					//값을 입력하였으므로 제거
	}
	cout << Cards.front() << endl;//큐에 남은 하나의 값을 출력

}