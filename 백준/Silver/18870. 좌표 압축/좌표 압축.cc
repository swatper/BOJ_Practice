#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare_1(pair<int, int>a, pair<int, int>b);
bool Compare_2(pair<int, int>a, pair<int, int>b);
void CoordinateCompression(vector<pair<int, int>> &list);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int>> list; //{인덱스(넣은 순서), 값}
	for (int i = 0; i < N; i++) {
		int element;
		cin >> element;
		list.push_back({i , element});
	}
	//값 기준 정렬
	sort(list.begin(), list.end(), Compare_1);
	//좌표 압축
	CoordinateCompression(list);
	//인덱스(들어온 순서) 기준 정렬
	sort(list.begin(), list.end(), Compare_2);

	//결과 확인
	for (int i = 0; i < N; i++)
		cout << list[i].second << ' ';
	cout << '\n';

	return 0;
}

//오름차순 정렬
bool Compare_1(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}
//오름차순 정렬
bool Compare_2(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

void CoordinateCompression(vector<pair<int, int>>& list) {
	int preValue = list[0].second; //이전 값과 비교용
	list[0].second = 0; //값 대신 새로 기록할 인덱스
	for (int i = 1; i < list.size(); i++){
		if (preValue == list[i].second){
			list[i].second = list[i - 1].second;
			continue;
		}
		preValue = list[i].second;
		list[i].second = list[i - 1].second + 1;
	}
}