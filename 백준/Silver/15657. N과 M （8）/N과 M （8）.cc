#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int* list, int* tmpCase, int size, int start, int curDept, int maxDept);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int * numbers = new int[N];
	int*numCase= new int[N];
	for (int i = 0; i < N; i++){
		cin >> numbers[i];
	}
	//오름차순 정렬
	sort(numbers, numbers + N);
	//탐색 시작
	DFS(numbers, numCase,  N, 0, 0, M);

	return 0;
}

void DFS(int* list, int* tmpCase, int size ,int start, int curDept, int maxDept) {
	//최대 깊이까지 내려오면 하나의 수열 완성 -> 출력
	if (curDept == maxDept) {
		for (int i = 0; i < maxDept; i++)
			cout << tmpCase[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = start; i < size; i++){
			//수열 저장
			tmpCase[curDept] = list[i];
			//다시 탐색(재귀)
			DFS(list, tmpCase, size, i, curDept+1, maxDept);
		}
	}
}
