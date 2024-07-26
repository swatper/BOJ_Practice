#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> Scores;
	int Level, Score, Count = 0;
	cin >> Level;
	for (int i = 0; i < Level; i++){
		//각 레벨의 점수 입력 받기
		cin >> Score;
		Scores.push_back(Score);
	}
	//점수 감소 시키기
	for (int i = Scores.size() - 1; i > 0; i--){
		if (Scores[i] <= Scores[i - 1]){
			Count += Scores[i - 1] - Scores[i] + 1;
			Scores[i - 1] -= (Scores[i - 1] - Scores[i]) + 1;
		}
	}
	cout << Count << "\n";
	return 0;
}