#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfSite, targets;
	string domain, password, targetSite;
	map<string, string> siteList;
	cin >> numOfSite >> targets;
	//사이트 주소 및 비밀번호 저장
	for (int i = 0; i < numOfSite; i++){
		cin >> domain >> password;
		siteList.insert({domain , password});
	}
	//찾기
	for (int i = 0; i < targets; i++){
		cin >> targetSite;
		cout << siteList[targetSite] << "\n";
	}
	return 0;
}