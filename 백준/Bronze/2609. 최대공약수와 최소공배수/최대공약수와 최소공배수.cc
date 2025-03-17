#include <iostream>
using namespace std;

int Euclidean(int A, int B);
int LeastCommonMultiple(int A, int B);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;
	cout << Euclidean(A, B) << "\n" << LeastCommonMultiple(A, B) << "\n";
	return 0;
}

//유클리드 호제법으로 최대공약수 구하기
	//큰 숫자를 작은 숫자로 나눈 나머지 구허기
	//작은 숫자를 나눈 나머지 값으로 다시  나누기
	//나눈 나머지 값이 0이 될때까지 반복
int Euclidean(int A, int B) {
	if (A < B) {
		int swap = A;
		A = B;
		B = swap;
	}

	int result = A % B;
	while (result != 0) {
		A = B;
		B = result;
		result = A % B;
	}
	return B;
}

//최소공배수 x 최대공약수 = 두 수의 곱
	//-> 최소공배수 = 두 수의 곱 / 최대공약수
int LeastCommonMultiple(int A, int B) {
	int tmp = Euclidean(A, B);
	return (A * B) / tmp;
}