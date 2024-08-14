#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int CoinTypes, Price, Coins = 0;
	cin >> CoinTypes >> Price;
	//Coins의 값만 큼 최소 크기 설정
	vector<int> Coin(CoinTypes);

	//종류 입력 받기 (오름차순으로 입력 받음)
	for (int i = 0; i < CoinTypes; i++){
		cin >> Coin[i];
	}

	//필요한 동전 수 계산
	for (int i = Coin.size() - 1; i >= 0; i--){
		Coins += Price / Coin[i];
		Price %= Coin[i];
	}

	cout << Coins << "\n";

	return 0;
}