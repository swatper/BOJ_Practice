#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		map<long long, int> area;
		long long soldiers;
		long long soldiernum = -1;
		cin >> soldiers;
		//땅에 있는 각 번호의 군인들 수 저장
		for (long long j = 0; j < soldiers; j++){
			long long number;
			cin >> number;
			area[number]++;
			//과반수 초과 확인
			if (area[number] *2 >soldiers) {
				//군인 번호 저장
				soldiernum = number;
			}
		}
		if (soldiernum != -1)
			cout << soldiernum << "\n";
		else
			cout << "SYJKGW \n";
	}
	return 0;
}
