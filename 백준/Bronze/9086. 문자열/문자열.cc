#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	string word;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		cin >> word;
		cout << word[0] << word[word.size() - 1] << '\n';
	}
	return 0;
}