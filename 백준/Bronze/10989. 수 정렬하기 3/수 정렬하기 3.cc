#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//0~10000까지 해당 숫자가 몇개 들어있는지 확인하는 배열
	int NumList[10001]{ 0, }; //배열 전체 0으로 초기화
	int Nums;
	cin >> Nums;
	for (int i = 0; i < Nums; i++){
		int Temp;
		cin >> Temp;
		//해당 숫자의 갯수 증가시킴
		NumList[Temp]++;
	}
	//해당 숫자(Index)에 저장된 값만 큼 숫자(Index)출력
	for (int i = 1; i < 10001; i++){
		for (int j = 0; j < NumList[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}    