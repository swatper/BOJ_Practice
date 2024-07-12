#include <iostream>
#define MAX 10001
using namespace std;

int d(int N);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//C++에서 bool 배열 초기화는 true로 안 해줌
	bool selfNumber[MAX] = { false };

	for (int i = 1; i < MAX; i++){
		int result = d(i);
		if (result < MAX){
			//생성 가능한 숫자 체크
			selfNumber[result] = true;
		}
	}

	//결과 확인
	for (int i = 1; i < MAX; i++){
		if (!selfNumber[i]){
			cout << i << "\n";
		}
	}
	return 0;
}

int d(int N) {
	int sum = N;
	//셀프 넘버 구하기
	while (N > 0) {
		//각 자리 숫자의 합 구하기
		sum += N % 10;
		N /= 10;
	}
	return sum;
}