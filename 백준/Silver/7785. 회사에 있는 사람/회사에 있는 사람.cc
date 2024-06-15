#include <iostream>
#include <map>
using namespace std;

//매핑 연습 5
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//기본적으로 map 클래스는 less<_KTy(키타입)>로 돼어있어
	//오름차순으로 정렬됨
	//그러므로 처음부터 내림차순으로 정렬하도록 설정
	map < string, bool, greater<string>> Employee;
	int Logs;
	cin >> Logs;
	//입력 받기
	for (int i = 0; i < Logs; i++){
		string Name, Type;
		cin >> Name >> Type;
		//퇴근한 사람은 Employee에서 지우기 
		if (Type == "leave"){
			Employee.erase(Name);
		}
		else{
			Employee.insert({Name, true});
		}
	}
	//출근한 사람 찾기
	for (auto Iter : Employee) {
		cout << Iter.first << "\n";
	}
	return 0;
}    
