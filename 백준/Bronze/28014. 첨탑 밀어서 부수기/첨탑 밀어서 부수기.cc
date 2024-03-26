#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Towers, Length,PreLength = 0, Try = 0;
	cin >> Towers;
	for (int i = 0; i < Towers; i++) {
		cin >> Length;
		//앞 첨탑의 높이와 현재 첨탑의 높이를 비교 
		if (PreLength <= Length) {
			Try++;
		}
		PreLength = Length;
	}
	cout << Try << "\n";
	return 0;
}