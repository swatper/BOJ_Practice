#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Word;
	int Index;
	cin >> Word>> Index;
	cout << Word[Index - 1] << "\n";
	return 0;
}