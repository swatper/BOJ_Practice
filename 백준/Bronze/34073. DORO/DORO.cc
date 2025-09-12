#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int words;
	cin >> words;
	for (int i = 0; i < words; i++){
		string word;
		cin >> word;
		cout << word + "DORO ";
	}
	cout << "\n";

	return 0;
}
