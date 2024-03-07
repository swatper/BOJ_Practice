#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Count = 0 ;
	string X = "";
	cin >> X;
	//한 자리 수가 될때까지 변환
	while (X.length() > 1) {
		Count++;
		int tmp = 0;
		for (int i = 0; i < X.length(); i++) {
			tmp += (int)X[i] % 48;
		}
		//더한 값을 X에 다시 넘김
		//to_string()을 이용하여 int를 string으로 변환
		X = to_string(tmp);
	}
	cout << Count << "\n";
	if (X == "3" || X == "6" || X == "9") {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	return 0;
}