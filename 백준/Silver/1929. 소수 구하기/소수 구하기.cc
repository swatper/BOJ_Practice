#include <iostream>
#define MAX 1000001
using namespace std;

bool numbers[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int start, end;
	numbers[0] = false;
	numbers[1] = false;
	for (int i = 2; i < MAX; i++)
		numbers[i] = true;

	cin >> start >> end;

	//필요한 구간만 계산
	for (int i = 2; i * i <= end; i++){
		if (numbers[i]) {
			for (int j = i * i; j <= end; j += i) {
				numbers[j] = false;
			}
		}
	}
	for (int i = start; i <= end; i++){
		if(numbers[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}