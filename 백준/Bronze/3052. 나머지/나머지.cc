#include <iostream>
using namespace std;

int main() {
	int NArray[42] = {};//42로 나눈 나머지를 인덱스로 사용
	int n = 0;//서로 다른 나머지의 갯수
	for (int i = 0; i <= 9; i++) {
		int num;
		cin >> num;//값 입력받기
		NArray[num % 42] = 1;//입력받은 값을 42로 나눈 후 그 값을 인덱스로하여 해당 인덱스의 값을 1로 저장 
	}
	for (int i = 0; i <= 41; i++) {
		if (NArray[i] == 1) {
			n += 1;//인덱스에 1이 저장된 인덱스의 갯수를 구함
		}
	}
	cout << n << endl;
	return 0;
}