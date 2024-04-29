#include <iostream>
#include <vector>
using namespace std;
//2차원 배열 연습
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Row, Column, Element;
	cin >> Row >> Column;
	//2차원 배열 생성: 배열이름(행, vector<int>(열, 초기값))
	vector<vector<int>> Result(Row, vector<int>(Column, 0));

	//값을 입력 받으면서 바로 더함(행렬 A)
	for (int i = 0; i < Row; i++){
		for (int j = 0;  j < Column;  j++){
			cin >> Element;
			Result[i][j] += Element;
		}
	}

	//값을 입력 받으면서 바로 더함(행렬 B)
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++){
			cin >> Element;
			Result[i][j] += Element;
		}
	}

	//결과 출력
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++){
			cout << Result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}