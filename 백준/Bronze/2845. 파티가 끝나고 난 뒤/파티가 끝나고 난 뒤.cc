#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int* News = new int[5];
	int People, Large, Total;
	cin >> People >> Large;
	Total = People * Large;
	for (int i = 0; i < 5; i++){
		cin >> News[i];
	}

	for (int i = 0; i < 5; i++){
		cout << News[i] - Total <<" ";
	}
	cout << "\n";
	return 0;
}