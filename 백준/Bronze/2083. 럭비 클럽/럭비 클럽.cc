#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Name;
	int Age, Weight;
	while (true){
		cin >> Name >> Age >> Weight;
		if (Name == "#" && Age == 0 && Weight == 0) {
			break;
		}
		//성인부 회원
		if (Age > 17 || Weight >= 80){
			cout << Name + " Senior\n";
		}
		//청소년부 회원
		else{
			cout << Name + " Junior\n";
		}
	}
	return 0;
}