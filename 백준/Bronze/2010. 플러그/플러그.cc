#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int Multitaps, Plugs = 1;
	cin >> Multitaps;
	for (int i = 0; i < Multitaps; i++){
		int Plug;
		cin >> Plug;
		Plugs += (Plug - 1);
	}
	cout << Plugs << "\n";
	return 0;
}    