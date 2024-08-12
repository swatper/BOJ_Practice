#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, Total = 0;
	cin >> N;
	for (int i = 1; i <= N; i++){
		Total += i;
	}
	cout << Total << "\n";
}