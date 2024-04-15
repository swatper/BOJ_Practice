#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NByte;
	cin >> NByte;
	for (int i = 0; i < NByte / 4; i++){
		cout << "long ";
	}
	cout << "int\n";
	return 0;
}