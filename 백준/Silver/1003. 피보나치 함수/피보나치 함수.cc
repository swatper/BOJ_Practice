#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    //각 피보나치 값에서 0의 개수와 1의 개수를 각각 저장
    int* FibonacciArray0 = new int[41];
    int* FibonacciArray1 = new int[41];
    //초기화
    for (int i = 0; i < 41; i++) {
        FibonacciArray0[i] = 0;
        FibonacciArray1[i] = 0;
    }
    //미리 피보나치 수열의 0과 1의 개수 계산
    FibonacciArray0[0] = 1;
    FibonacciArray1[0] = 0;
    FibonacciArray0[1] = 0;
    FibonacciArray1[1] = 1;
    //규칙성을 이용하여 배열의 값 저장
    for (int i = 2; i < 41; i++){
        FibonacciArray0[i] += FibonacciArray0[i - 1] + FibonacciArray0[i - 2];
        FibonacciArray1[i] += FibonacciArray1[i - 1] + FibonacciArray1[i - 2];
    }
    //Tc 입력받기
    int Tc;
    cin >> Tc;
    for (int i = 0;  i < Tc;  i++){
        int N;
        cin >> N;
        //해당 숫자를 index로하여 계산
        cout << FibonacciArray0[N]<< " " << FibonacciArray1[N] << "\n";
    }
	return 0;
}