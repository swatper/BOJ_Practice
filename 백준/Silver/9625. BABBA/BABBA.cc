#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int *A= new int[46];
	int *B = new int[46];
	A[0] = 1;
	A[1] = 0;
	A[2] = 1;
	B[0] = 0;
	B[1] = 1;
	B[2] = 1;
	for (int i = 3; i <= 45;i++) {
		//A의 갯수는 i - 1번째 단어의 B를 BA로 바꾸므로 B의 갯수와 같음
		A[i] = B[i - 1];
		//B의 갯수는 i - 1번째 단어의 A를 B로 바꾸므로, A의 갯수과 같지만
		//i -i번째 단어의 B를 BA로 바꾸므로 B의 갯수는 변화가 없어서
		// i - 1 번째의 A의 갯수와 B의 갯수를 더하면 됨 
		B[i] = A[i - 1] + B[i - 1];
	}
	int Try;
	cin >> Try;
	cout << A[Try] << " " << B[Try];
	return 0;
}