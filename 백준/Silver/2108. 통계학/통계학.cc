#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define CORRECTION 4000
using namespace std;

bool Compare(int a, int b) {
	return a < b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int numbers, number, maxCount = 0;
	int AVG = 0, MED = 0, MOD = 0, RNG = 0;
	bool isSecond = false;
	//중복 횟수를 저장할 배열
	vector<int> allCounter(8001, 0);
	//실제 값들을 저장할 배열
	vector<int> list;

	cin >> numbers;

	//입력받기
	for (int i = 0; i < numbers; i++){
		cin >> number;
		AVG += number;
		//입력 받은 값을 양수로 보정(4000 더함)
		number += CORRECTION;
		allCounter[number]++;
		list.push_back(number);
	}
	//오름차순 정렬
	sort(list.begin(), list.end(), Compare);

	//산술평균
	AVG = round((double)AVG / numbers);
	//중앙값(보정값 빼기)
	MED = list[numbers / 2] - CORRECTION;
	//최빈값
	for (int i = 0; i < 8001; i++){
		if (maxCount <= allCounter[i]) {
			//빈도수가 같으면
			if (maxCount == allCounter[i] && !isSecond) {
				MOD = i;
				isSecond = true;
			}
			else if (maxCount < allCounter[i]){
				isSecond = false;
				maxCount = allCounter[i];
				MOD = i;
			}
		}
	}
	//범위
	RNG = list[numbers - 1] - list[0];

	cout << AVG << "\n" << MED << "\n" << MOD - CORRECTION << "\n" << RNG << "\n";
	return 0;
}