#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Students[31] = { 0 }; //배열을 1으로 초기화
	for (int i = 1; i <= 28; i++) {
		int student_num;
		cin >> student_num;
		Students[student_num] = 1;
	}
	for (int i = 1; i <= 30;i++) {
		if (Students[i] == 0) {
			cout << i << "\n";
		}
	}
	return 0;
}