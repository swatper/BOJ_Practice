#include <iostream>
#define MAX 5001
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Kg;
	int List[MAX] = {};
	for (int i = 0; i < MAX; i++) {
		List[i] = 5000;
	}
	List[3] = 1;
	List[5] = 1;
	for (int i = 6; i < MAX; i++) {
		List[i] = (List[i - 3] <= List[i - 5]) ? (List[i - 3] + 1) : (List[i - 5] + 1);
	}
	cin >> Kg;
	if (List[Kg] >= 5000) {
		cout << "-1\n";
	}
	else {
		cout << List[Kg] << "\n";
	}
	return 0;
}