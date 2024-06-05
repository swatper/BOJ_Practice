#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//매핑 연습
	map<string, int> Person;
	//듣보잡 목록
	vector<string> NoListenedNoHeard;
	int NoListenedList, NoHeardList;
	cin >> NoListenedList >> NoHeardList;
	//듣도 못한 사람, 듣도 못한 사람 입력 받기
	for (int i = 0; i < NoListenedList + NoHeardList; i++){
		string name;
		cin >> name;
		//map에 key값이 name인 사람이 있으면
		//value에 1을 더하고 없으면
		//key값이 name이고 value가 1인 사람을 추가
		Person[name]++;
		if (Person[name] > 1){
			//2이상이면 듣고 보도 못한 사람임
			NoListenedNoHeard.push_back(name);
		}
	}
	//듣보잡 인원 수 출력
	cout << NoListenedNoHeard.size() << "\n";
	//정렬
	sort(NoListenedNoHeard.begin(), NoListenedNoHeard.end());
	//foreach문 사용
	for (string name : NoListenedNoHeard){
		cout << name + "\n";
	}
	return 0;
}