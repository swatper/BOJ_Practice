#include <iostream>
#define MAX 9
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int* scale = new int[MAX];
	int ACS = 0;
	int DES = 8;

	//음계 입력 받기
	for (int i = 1; i < MAX; i++){
		cin >> scale[i];
		if (scale[i] == i)
			ACS++;
		if (scale[i] == DES)
			DES--;
	}

	if (ACS == 8)
		cout << "ascending\n";
	else if (DES == 0)
		cout << "descending\n";
	else
		cout << "mixed\n";

	return 0;
}
