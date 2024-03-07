#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Array[5] = {};		//다섯 개의 자연수를 담을 배열
	for (int i = 0; i < 5; i++) {
		cin >> Array[i];	//다섯 개의 자연수 입력받기 
	}

	//특정 최소공배수가 다섯 개의 자연수 중 세개 이상이 공배수가 되는 값을 구하는 과정
	int N = 1;			//공배수가 되는 값
	while (true) {		//무한반복
		int count = 0;					//N과 공배수가 되는 자연수의 수 
		for (int i = 0; i < 5; i++) {	//각각의 자연수를 N으로 나눔
			if (N % Array[i] == 0) {	//N을 i번째 배열의 자연수로 나누었을 때 나머지가 0이면
				count++;				//N은 그 자연수의 배수이므로 count를 증가
			}
		}
		if (count >= 3) {	//N값과 공배수가 되는 자연수의 수가 3이상이면
			break;			//5개 중 3개 이상의 자연수의 공배수가 되므로 while문 중단
		}
		//cout가 3미만이므로 N은 대부분의 배수가 아님->  N을 증가시켜 반복실행 
		N++;
	}
	cout << N << "\n";
	return 0;
}