#include <iostream>
using namespace std;

int main() {
	int count = 99;
	int N;
	cin >> N;
	if (N < 100) {//99전까지 모든 수는 한수임
		cout << N << "\n";
	}
	else {
		for (int i = 100; i <= N; i++) {
			int ones, Tens, Hundreds;
			ones = i % 10;
			Tens = (i / 10) % 10;
			Hundreds = i/100;
			if ((Hundreds - Tens) == (Tens - ones)) {//등차가 같으면
				count++;
			}
		}
		cout << count << "\n";
	}
}