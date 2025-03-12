#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b);

int main() {
	int N, x, y;
	vector<pair<int, int>> pos;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> x >> y;
		pos.push_back({x, y});
	}

	//정렬
	sort(pos.begin(), pos.end(), Compare);

	for (int i = 0; i < N; i++) {
		cout<< pos[i].first << " "  << pos[i].second<< "\n";
	}

	return 0;
}

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}