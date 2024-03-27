#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Students, Pride;
	cin >> Students >> Pride;
	//배열 생성
	int* ScoreArray = new int[Students];
	for (int i = 0; i < Students; i++) {
		cin >> ScoreArray[i];
	}
	//오름차순으로 정렬
	sort(ScoreArray, ScoreArray+Students);
	//오름차순으로 정렬하였으므로 뒤에서 Pride번째의 값을 출력하면 커트라인을 알 수 있음
	cout << ScoreArray[Students - Pride] << "\n";
	return 0;
}