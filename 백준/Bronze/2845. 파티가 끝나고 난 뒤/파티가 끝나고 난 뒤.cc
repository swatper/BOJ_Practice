#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int People, Large, Total, News;
	cin >> People >> Large;
	Total = People * Large;
	for (int i = 0; i < 5; i++){
		cin >> News;
		cout << News - Total << " ";
	}
	cout << "\n";
	return 0;
}