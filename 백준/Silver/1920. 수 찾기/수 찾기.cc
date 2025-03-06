#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(int a, int b);
bool BinarySearch(int* list, int size, int target);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n;

	int *numbers = new int[n];
	for (int i = 0;  i < n; i++)
		cin >> numbers[i];

	sort(numbers, numbers + n, Compare);

	cin >> m;
	for (int i = 0; i < m; i++){
		int target;
		cin >> target;

		string result = BinarySearch(numbers, n ,target) ? "1" : "0";
		cout << result << "\n";
	}

}

//오름차순 정렬
bool Compare(int a, int b) {
	return a < b;
}

/// <summary>
/// 이분탐색 시작작
/// </summary>
/// <param name="list">: 배열</param>
/// <param name="size">: 배열의 크기</param>
/// <param name="target">: 찾으려는 수</param>
/// <returns></returns>
bool BinarySearch(int *list, int size,int target) {
	int front = 0;
	int back = size - 1;
	int mid;
	while (front <= back) {
		mid = (front + back) / 2;
		
		if (list[mid] == target)
			return true;

		if (list[mid] > target)
			back = mid - 1;
		else
			front = mid + 1;
	}
	return false;
}