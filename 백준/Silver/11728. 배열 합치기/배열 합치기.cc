#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> ListA, ListB;
	int SizeA, SizeB;
	cin >> SizeA >> SizeB;
	//입력 받기
	for (int i = 0; i < SizeA; i++){
		int Temp;
		cin >> Temp;
		ListA.push_back(Temp);
	}

	for (int i = 0; i < SizeB; i++){
		int Temp;
		cin >> Temp;
		ListB.push_back(Temp);
	}
	//각각 배열의 인덱스를 의미하는 변수
	int IndexA =0, IndexB = 0;
	while (IndexA < SizeA && IndexB < SizeB){
		if (ListA[IndexA] <= ListB[IndexB]){
			cout << ListA[IndexA++] << " ";
		}
		else{
			cout << ListB[IndexB++] << " ";
		}
	}
	//두 배열의 길이가 다르면, 길이가 긴 배열의 원소가 남게됨(?)
	while (IndexA < SizeA){
		cout << ListA[IndexA++] << " ";
	}
	while (IndexB < SizeB){
		cout << ListB[IndexB++] << " ";
	}
	cout << "\n";
	return 0;
}