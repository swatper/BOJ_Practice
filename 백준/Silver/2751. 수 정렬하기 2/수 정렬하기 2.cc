#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(int a, int b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	int* numbers = new int[N];

	for (int i = 0; i < N; i++)
		cin >> numbers[i];
	
	sort(numbers, numbers + N, Compare);

	for (int i = 0; i < N; i++)
		cout << numbers[i] << "\n";

	return 0;
}

bool Compare(int a, int b) {
	return a < b;
}