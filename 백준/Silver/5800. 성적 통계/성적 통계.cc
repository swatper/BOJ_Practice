#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ScoreCompair(int ScoreA, int ScoreB);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfClass;
	cin >> numOfClass;
	for (int i = 0; i < numOfClass; i++){
		int students, min, max, gap = 0;
		vector<int> studentsScore;
		cin >> students;
		//해당 반의 학생들 점수 입력 받기
		for (int j = 0; j < students; j++){
			int Score;
			cin >> Score;
			studentsScore.push_back(Score);
		}
		//내림 차순으로 정렬
		sort(studentsScore.begin(), studentsScore.end(), ScoreCompair);
		min = studentsScore.back();
		max = studentsScore.front();
		//차이값 찾기
		for (int j = 1; j < students; j++) {
			int temp = studentsScore[j - 1] - studentsScore[j] ;
			gap = gap > temp ? gap : temp;
		}
		cout << "Class " << i + 1 << "\n";
		cout << "Max " << max << ", Min " << min << ", Largest gap " << gap << "\n";
	}
	return 0;
}

bool ScoreCompair(int ScoreA, int ScoreB) {
	return ScoreA > ScoreB;
};