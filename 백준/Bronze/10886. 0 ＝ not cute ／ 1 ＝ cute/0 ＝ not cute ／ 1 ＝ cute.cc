#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//unsigned를 붙여 0 ~ 약 42억까지 표현되도록 하기
	int peoples, poinion ,count0 = 0, count1 = 0 ;
	string result;
	cin >> peoples;
	for (int i = 0; i < peoples; i++){
		cin >> poinion;
		switch (poinion) {
		case 0:
			count0++;
			break;
		case 1:
			count1++;
			break;
		}
	}
	result = (count0 > count1) ? "Junhee is not cute!\n" : "Junhee is cute!\n";
	cout << result;
	return 0;
}