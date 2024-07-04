#include <iostream>
#include <map>
using namespace std;

//매핑 연습 11
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, bool> DanceList;
	DanceList.insert({ "ChongChong" , true});
	int meetigs;
	cin >> meetigs;
	for (int i = 0; i < meetigs; i++){
		string personA, personB;
		cin >> personA >> personB;
		if (DanceList.find(personA) != DanceList.end()) {
			DanceList.insert({ personB , true });
		}
		else if (DanceList.find(personB) != DanceList.end()){
			DanceList.insert({ personA, true });
		}
	}
	cout << DanceList.size() << "\n";
	return 0;
}
//map[이름]으로 찾을 때, map에 {이름, 0}이 저장되는 문제 발생
//참고: https://80000coding.oopy.io/8af406a3-b3b1-4f3f-b190-2937b23684ed