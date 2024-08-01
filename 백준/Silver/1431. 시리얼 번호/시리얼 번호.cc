#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//정렬 기준
bool Compare(string NumA, string NumB) {
	int NumALength = NumA.size();
	int NumBLength = NumB.size();
	int NumASum = 0;
	int NumBSum = 0;
	//길이 비교
	if (NumALength != NumBLength){
		return NumALength < NumBLength;
	}
	//합 계산
	for (int i = 0; i < NumALength; i++){
		//숫자만 더하기
		if (NumA[i] >= 48 && NumA[i]<= 57) {
			NumASum += NumA[i] - 48;
		}
		if (NumB[i] >= 48 && NumB[i] <= 57)
		{
			NumBSum += NumB[i] - 48;
		}
	}
	//합 비교
	if (NumASum != NumBSum){
		return NumASum < NumBSum;
	}
	//사전순 비교
	else {
		return NumA < NumB;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> SerialNumberList;
	string serialNumber;
	int guitars;

	cin >> guitars;
	for (int i = 0; i < guitars; i++){
		cin >> serialNumber;
		SerialNumberList.push_back(serialNumber);
	}
	//정렬
	sort(SerialNumberList.begin(), SerialNumberList.end(), Compare);

	for (int i = 0; i < guitars; i++){
		cout << SerialNumberList[i]  + "\n";
	}
	return 0;
}