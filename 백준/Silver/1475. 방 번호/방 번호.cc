#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Num;
	int Max = 0;
	int Set[9] = {0,};
	cin >> Num;
	for (int i = 0; i < Num.size(); i++) {
		int Temp = Num[i] - '0';
		//6과 9는 같은 숫자로 생각
		if (Temp == 6 || Temp == 9){
			Set[6]++;
		}
		else{
			Set[Temp]++;
		}
	}
	//6또는 9 만드는데 필요한 세트 개수 계산
	if (Set[6] % 2 == 0){
		Set[6] /= 2;
	}
	else{
		Set[6] = (Set[6] / 2) + 1;
	}
	
	for (int i = 0; i < 9; i++){
		Max = Max > Set[i] ? Max : Set[i];
	}

	cout << Max << "\n";
	return 0;
}