#include <iostream>
using namespace std;

int main() {
	int Pn = 0;  //소수의 갯수를 저장할 변수
	int n = 0; //주어지는 n 의 값
	cin >> n; // n 입력 받기
	int *NArray = new int [n]; // 입력받은 n 만큼 배열 만들기, 동적할당

	for (int a = 0; a < n; a++) {
		cin >> NArray[a];//n 개의 숫자를 배열에 입력받기
		//밑에는 입력받은 값이 소수인지 확인하는 과정
		for (int b = 2; b <= NArray[a]; b++) {//배열의 입력된 값보다 작은 값들을 계속 나누고 증가시켜 다시 나누는 과정을 반복
			if (NArray[a] == 2 || b == NArray[a] - 1) { 
				Pn++; } //나누는 과정을 계속하였을 때 나누는 값이 배열의 값보다 1 작을 때까지 진행하였으면 소수 
			else if (NArray[a] % b == 0) {//만약 입력된 값을 작은 값으로 나누었을 떄 나머지가 0이면 소수가 아님
				break; }//이미 소수가 아니므로 더이상 작은 숫자들을 나눌 필요가 없음
		}
	}
	cout << Pn;
	delete[] NArray;
	return 0;
}