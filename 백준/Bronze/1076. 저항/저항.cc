#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string resistances[10] = {"black", "brown", "red",  "orange", "yellow", "green", "blue", "violet", "grey", "white"};
	string targetrR[3];
	long long result = 0;
	for (int i = 0; i < 3; i++)
		cin >> targetrR[i];
	//앞 두 저항 색 확인
	for (int i = 0; i < 2; i++){
		result *= 10;
		for (int j = 0; j < 10; j++){
			if (targetrR[i] == resistances[j]) {
				result += j;
				break;
			}
		}
	}
	//마지막 저항 값 확인
	for (int i = 0; i < 10; i++) {
		if (targetrR[2] == resistances[i])
			break;
		result *= 10;
	}
	cout << result << '\n';
	return 0;
}