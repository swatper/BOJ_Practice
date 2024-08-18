#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Try, Target, Count = 0;
	cin >> Try;
	int* Numbers = new int[Try];
	for (int i = 0; i < Try; i++) {
		cin >> Numbers[i];
	}
	cin >> Target;

	for (int i = 0; i < Try; i++) {
		if (Numbers[i] == Target) {
			Count++;
		}
	}
	cout << Count << "\n";
	return 0;
}