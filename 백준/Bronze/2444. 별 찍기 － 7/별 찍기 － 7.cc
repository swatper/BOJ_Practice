#include <iostream>
#define MAX 1000000000
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int stars;
	cin >> stars;
	//다이아몬드 윗쪽
	for (int i = 1; i <= stars ; i++) {
		for (int a = i; a <= stars - 1;a++) {
			cout << " ";
		}
		for (int b = 1; b <= (i * 2) - 1; b++) {
			cout << "*";
		}
		cout << "\n";
	}
	//다이아몬드 아래쪽
	for (int i = stars-1; i >=1; i--) {
		for (int a = i; a <= stars - 1; a++) {
			cout << " ";
		}
		for (int b = 1; b <= (i * 2) - 1; b++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
} 