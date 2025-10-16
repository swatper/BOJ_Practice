#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	string Ac;
	int size;
	string array;
	for (int i = 0; i < Tc; i++){
		cin >> Ac;
		cin >> size;
		cin >> array;
		bool isError = false, isReverse = false;
		deque<int> resultArr;
		string tmp = "";
		for (int j = 1; j < array.size(); j++){
			if ((array[j] == ',' || array[j] == ']') && tmp!="") {
				resultArr.push_back(stoi(tmp));
				tmp = "";
			}
			//두 자릿수 이상인 원소에 대한 처리
			else
				tmp += array[j];
		}
		//AC함수 실행
		for (int j = 0; j < Ac.size(); j++) {
			if (Ac[j] == 'R')
				isReverse = !isReverse;
			else  if (Ac[j] == 'D') {
				if (resultArr.empty()) {
					isError = true;
					break;
				}
				if (isReverse)
					resultArr.pop_back();
				else
					resultArr.pop_front();
			}
		}

		if (isReverse)
			reverse(resultArr.begin(), resultArr.end());

		//결과 확인
		if (isError)
			cout << "error\n";
		else {
			cout << '[';
			for (int j = 0; j < resultArr.size(); j++){
				if (j == resultArr.size() - 1) {
					cout << resultArr[j];
				}
				else
					cout << resultArr[j] << ',';
			}
			cout << "]\n";
		}
	}
	return 0;
}
