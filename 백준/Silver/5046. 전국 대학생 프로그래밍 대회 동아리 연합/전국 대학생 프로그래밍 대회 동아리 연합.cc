#include <iostream>
#define MAX 210000000
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int students, money, hotels, days, total = MAX;
	bool flag = false;
	cin >> students >> money >> hotels >> days;
	for (int i = 0; i < hotels; i++){
		int price;
		cin >> price;
		for (int j = 0; j < days; j++){
			int rooms;
			cin >> rooms;
			//투숙 가능한 인원이 학생수 보다 적거나 예산을 초과하면 넘김
			if (rooms < students || price * students > money){
				continue;
			}
			flag = true;
			total = total > price * students ? price * students : total;
		}
	}
	if (flag){
		cout << total << "\n";
	}
	else {
		cout << "stay home\n";
	}
	return 0;
}