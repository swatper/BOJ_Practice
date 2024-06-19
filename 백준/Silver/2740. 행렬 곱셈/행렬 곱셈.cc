#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//2차원 백터 만들기
	int N, M;
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> A[i][j];
		}

	}
	int K;
	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K, 0));
	for (int i = 0; i < M; i++){
		for (int j = 0; j < K; j++){
			cin >> B[i][j];
		}
	}
	//행렬 곱 연산
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < K; b++) {
			int Result = 0;
			for (int c = 0; c < M; c++){
				Result += A[a][c] * B[c][b];
			}
			cout << Result << " ";
		}
		cout << "\n";
	}
	return 0;
}    