#include <iostream>
using namespace std;

struct ColoredCity
{
	//각 색깔의 도시 소유 개수별 가치
	int coloredCityValue[4] = {0,};
};

struct PlayerOwnCity
{
	//도시 색깔별 보유 도시 수
	int ownCityColor[10] = { 0 };
};

void CheckCityOwn(string cityOwnStatus, PlayerOwnCity* P1, PlayerOwnCity* P2);
int CheckCapitalMoney(PlayerOwnCity* player, ColoredCity ciryData[]);
void CalculateTotalMoney(int* target, PlayerOwnCity* player, ColoredCity cityData[], int cash, int cashValue);
int CheckDambo(string ownStatus, string dambo, char target, int value);
void DoTrade(string* ownStatus, string TradeStatus);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ColoredCity cityData[10];
	PlayerOwnCity own[4];
	string cityownStatus, tradeStatus, damboStatus;
	int myMoney[2] = { 0 , };
	int myCash;
	int oppoMoney[2] = { 0 ,};
	int oppoCash;
	int cashValue, damboPenalty;
	int tradeFee[2] = {0,};
	//도시 가치 정보 입력
	for (int i = 0; i < 10; i++){
		cin >> cityData[i].coloredCityValue[0] >> cityData[i].coloredCityValue[1] >> 
					cityData[i].coloredCityValue[2] >> cityData[i].coloredCityValue[3];
	}
	//각 도시 상태 입력
	cin >> cityownStatus;
	cin >> tradeStatus;
	cin >> damboStatus;
	//현금 입급
	cin >> myCash;
	cin >> oppoCash;
	//거래 비용
	cin >> tradeFee[0];
	cin >> tradeFee[1];
	//현금 가치
	cin >> cashValue;
	//담보 패널티
	cin >> damboPenalty;

	//색깔별 보유 도시 수 계산
	CheckCityOwn(cityownStatus, &own[0], &own[1]);
	//거래 전 총자산 계산
	CalculateTotalMoney(&myMoney[0], &own[0], cityData, myCash, cashValue);
	CalculateTotalMoney(&oppoMoney[0], &own[1], cityData, oppoCash, cashValue);
	myMoney[0] += CheckDambo(cityownStatus, damboStatus, '1', damboPenalty);
	oppoMoney[0] += CheckDambo(cityownStatus, damboStatus, '2', damboPenalty);

	//거래
	DoTrade(&cityownStatus, tradeStatus);
	//수수료 계산
	myCash -= (tradeFee[0] - tradeFee[1]);
	oppoCash -= (tradeFee[1] - tradeFee[0]);
	//거래 후 총 자산 계산
	CheckCityOwn(cityownStatus, &own[2], &own[3]);
	CalculateTotalMoney(&myMoney[1], &own[2], cityData, myCash, cashValue);
	CalculateTotalMoney(&oppoMoney[1], &own[3], cityData, oppoCash, cashValue);
	myMoney[1] += CheckDambo(cityownStatus, damboStatus, '1', damboPenalty);
	oppoMoney[1] += CheckDambo(cityownStatus, damboStatus, '2', damboPenalty);

	if ((myMoney[1] - oppoMoney[1]) >= (myMoney[0]) - oppoMoney[0])
		cout << "YES \n";
	else
		cout << "NO \n";

	return 0;
}

void CheckCityOwn(string cityOwnStatus, PlayerOwnCity *P1, PlayerOwnCity *P2) {
	//도시 색깔
	int colorType = 0; 
	for (int i = 0; i < 40; i++){
		colorType = i / 4;
		if (cityOwnStatus[i] == '0')
			continue;
		else if (cityOwnStatus[i] == '1')
			P1->ownCityColor[colorType]++;
		else if (cityOwnStatus[i] == '2')
			P2->ownCityColor[colorType]++;
	}
}

int CheckCapitalMoney(PlayerOwnCity *player, ColoredCity cityData[]) {
	int totalMoney = 0;
	for (int i = 0; i < 10; i++){
		if (player->ownCityColor[i] == 0) {
			continue;
		}
		totalMoney += cityData[i].coloredCityValue[(player->ownCityColor[i]) - 1];
	}
	return totalMoney;
}

void CalculateTotalMoney(int * target, PlayerOwnCity* player, ColoredCity cityData[], int cash, int cashValue) {
	*target += CheckCapitalMoney(player, cityData) + (cash * cashValue / 100);
}

int CheckDambo(string ownStatus, string dambo, char target, int value) {
	int dambos = 0;
	for (int i = 0; i < 40; i++){
		if (ownStatus[i] == '0' || dambo[i] == '0') {
			continue;
		}
		if (target == ownStatus[i]) {
			dambos++;
		}
	}
	return -(dambos *value);
}

void DoTrade(string *ownStatus, string TradeStatus) {
	for (int i = 0; i < 40; i++){
		if (TradeStatus[i] == '0') {
			continue;
		}
		else {
			(*ownStatus)[i] = TradeStatus[i];
		}
	}
}