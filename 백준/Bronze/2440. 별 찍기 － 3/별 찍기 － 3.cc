#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Stars;
	cin >> Stars;
	//별찍기
	for (int i = Stars; i >= 1; i--){
		for (int j = i; j >= 1; j--){
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}