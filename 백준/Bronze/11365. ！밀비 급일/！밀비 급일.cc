#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Cryptogram;
	while (true) {
		getline(cin, Cryptogram);
		if (Cryptogram == "END")
		{
			break;
		}
		for (int i = (Cryptogram.length() - 1); i >= 0; i--){
			cout << Cryptogram[i];
		}
		cout << "\n";
	}
	return 0;
}