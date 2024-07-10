#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, Count = 0;
	cin >> N;
	//완전 제곱수면 항상 열린 상태
	for (int i = 1; i * i <= N; i++){
		Count++;
	}
	cout << Count << "\n";
	return 0;
}