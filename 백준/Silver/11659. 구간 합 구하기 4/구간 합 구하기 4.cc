#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	//누적 합 이용
	int* NArray = new int[N];		//입력받는 배열
	int* total_Array = new int[N];	//누적 합을 저장할 배열
	total_Array[0] = 0;
	NArray[0] = 0;
	for (int a = 1; a <= N; a++) {
		cin >> NArray[a];
		if (a  == 1) {
			total_Array[a] = NArray[a];
			//cout << total_Array[a] << "\n";
		}
		else {
			total_Array[a] = NArray[a] + total_Array[a - 1];
			//cout << total_Array[a] << "\n";
		}
	}
	for (int b = 1; b <= M; b++) {
		int result = 0;
		int i, j;
		cin >> i >> j;
		result = total_Array[j] - total_Array[i - 1];
		cout << result << "\n";
	}
	return 0;
}