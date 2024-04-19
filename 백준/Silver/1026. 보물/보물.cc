#include <iostream>
#include <algorithm>
using namespace std;

//sort()의 정렬하는 방법을 새로 정의
bool Compair(int a, int b) {
	return a > b;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Nums, Total = 0;
	cin >> Nums;
	int* ANums = new int[Nums];
	int* BNums = new int[Nums];
	for (int i = 0; i < Nums; i++)
	{
		cin >> ANums[i];
	}
	for (int i = 0; i < Nums; i++)
	{
		cin >> BNums[i];
	}
	//오름차순 정렬
	sort(ANums, ANums + Nums);
	//문제에 B는 재배치 하지말라고 하였으나, 재배치를 해도 결과가 같음
	//내림차순 정렬
	sort(BNums, BNums + Nums, Compair);
	for (int i = 0; i < Nums; i++){
		Total += ANums[i] * BNums[i];
	}
	cout << Total << "\n";
	return 0;
}