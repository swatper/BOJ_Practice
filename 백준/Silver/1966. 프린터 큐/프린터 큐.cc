#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(int a, int b) {
	return a < b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Tc, papaers, target, importance;

	cin >> Tc;

	for (int i = 0; i < Tc; i++){
		int sequence = 0;
		vector<int> PPImportance;
		queue<pair<int, int>> PPSQnumber;
		cin >> papaers >> target;

		for (int j = 0; j < papaers; j++){
			cin >> importance;
			PPImportance.push_back(importance);
			PPSQnumber.push({ j , importance });
		}

		//오름 차순 정렬
		sort(PPImportance.begin(), PPImportance.end(), Compare);

		//순서 찾기
		while (!PPSQnumber.empty()) {
			int curIndex = PPSQnumber.front().first;
			int curImportance = PPSQnumber.front().second;
			PPSQnumber.pop();

			//오름 차순으로 정렬된 배열의 맨 뒤에 값(가장 큰 값)과 비교하여 
			//큐에서 pop할지, 다시 넣을지 비교
			if (curImportance == PPImportance[PPImportance.size() - 1]) {
				PPImportance.pop_back();
				sequence++;
				if (curIndex == target) {
					cout << sequence << "\n";
					break;
				}
			}
			//다시 넣기
			else
				PPSQnumber.push({curIndex, curImportance});
		}
	}
	return 0;
}

