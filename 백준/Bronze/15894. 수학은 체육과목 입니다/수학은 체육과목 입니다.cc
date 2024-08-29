#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//unsigned를 붙여 0 ~ 약 42억까지 표현되도록 하기
	unsigned int Blocks;
	cin >> Blocks;
	cout << Blocks * 4 << "\n";
	return 0;
}