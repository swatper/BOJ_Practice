#include <iostream>
#include <map>
#include <vector>
using namespace std;

//매핑 연습 10
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, int> BattleList;
	vector<int> HyunWoo;
	int Battles, Score = 0;
	cin >> Battles;
	for (int i = 1; i <= Battles; i++){
		string name;
		cin >> name;
		//정답 저장
		BattleList.insert({name, i});
	}
	
	for (int i = 0; i < Battles; i++){
		string name;
		cin >> name;
		//현우 답 저장
		HyunWoo.push_back(BattleList[name]);
	}

	//정답 확인(쌍)
	for (int i = 0; i < Battles; i++){
		for (int j = i + 1; j < Battles; j++) {
			if (HyunWoo[i] < HyunWoo[j]) {
				Score++;
			}
		}
	}
	
	cout << Score << "/" << (Battles*(Battles - 1) / 2) << "\n";
	return 0;
}    