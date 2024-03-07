#include <iostream>
#include <queue>
using namespace std;

//'큐'라는 템플릿을 이용하여 오세푸스 순열 만들기
//'큐'란 데이터의 삽입이 앞에서 일어나고
//뒤에서 일어나는 자료구조 중 하나 (줄서기) 
//'템플릿'이란 데이터 타입을 원하는 대로 정할 수 있는 함수
int main() {
	int N, K;
	cin >> N >> K;
	//'큐'라는 함수를 int형 데이터 타입으로 사용
	queue<int> First_queue;
	queue<int> Jose_queue;
	//처음 숫자들을 저장
	for (int a = 0; a < N; a++) {
		First_queue.push(a+1);
		//cout << "삽입\n";
	}
	//오세푸스 순열 만들기
	//처음 숫자들을 저장한 개수만큼 반복
	for (int b = 0; b < N; b++) {	
		//K-1번째까지 큐의 앞에 저장된 값들을 뒤로 보냄
		for (int c = 1; c < K; c++) {
			First_queue.push(First_queue.front());
			First_queue.pop();
		}
		//K번째 들어있는 값을 오세푸스 순열 큐에 삽입하고
		Jose_queue.push(First_queue.front());
		//K번째 들어있는 값을 삭제
		First_queue.pop();
		//cout << "삭제 \n";

	}
	//요세푸스 순열 출력
	cout << "<";
	for (int i = 0; i < N; i++) {
		cout << Jose_queue.front();
		Jose_queue.pop();
		if (i < N - 1) {
			cout << ", ";
		}
	}
	cout << ">\n";
	return 0;
}