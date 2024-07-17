#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 3; i++){
		int count = 0;
		char result;
		for (int j = 0; j < 4; j++){
			bool num;
			cin >> num;
			//0이 들어올 때 마다 count 증가
			if (!num){
				count++;
			}
		}
		switch (count){
		//모
		case 0:
			result = 'E';
			break;
		//도
		case 1:
			result = 'A';
			break;
		//개
		case 2:
			result = 'B';
			break;
		//걸
		case 3:
			result = 'C';
			break;
		//윳
		case 4:
			result = 'D';
			break;
		}
		cout << result << '\n';
	}
	return 0;
}