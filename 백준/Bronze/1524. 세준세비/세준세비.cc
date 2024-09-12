#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//오름차순 정렬
bool Desc(int a, int b) {
	return a < b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		int	SJSoldiers, SBSoldiers, Str;
		//내림차순으로 정렬 후 가장 약한(맨 뒤) 병사 제거(pop)
		vector<int> SJSoldierList, SBSoldierList;

		cin >> SJSoldiers >> SBSoldiers;

		for (int j = 0; j < SJSoldiers; j++){
			cin >> Str;
			SJSoldierList.push_back(Str);
		}
		for (int j = 0; j < SBSoldiers; j++){
			cin >> Str;
			SBSoldierList.push_back(Str);
		}
		//내림차순으로 정렬하기
		sort(SJSoldierList.begin(), SJSoldierList.end(),Desc);
		sort(SBSoldierList.begin(), SBSoldierList.end(),Desc);
		
		//전투 시작
		while (!SJSoldierList.empty() && !SBSoldierList.empty()){
			//맨 마지막(가장 약한) 병사 전투력 비교
			if (SJSoldierList[SJSoldierList.size() - 1] >= SBSoldierList[SBSoldierList.size() - 1]) {
				//세비 병사 사망
				SBSoldierList.pop_back();
			}
			else{
				//세준 병사 사망
				SJSoldierList.pop_back();
			}
		}
		
		//결과 확인
		if (!SJSoldierList.empty()){
			cout << "S\n";
		}
		else if (!SBSoldierList.empty()) {
			cout << "B\n";
		}
		else {
			cout << "C\n";
		}
	}
	return 0;
}