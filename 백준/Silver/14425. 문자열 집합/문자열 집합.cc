#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, bool> Group;
	int N, Find, Count = 0;
	cin >> N >> Find;
	for (int i = 0; i < N; i++){
		string Name;
		cin >> Name;
		//목록 추가
		Group.insert({ Name, true });
	}
	//찿기
	for (int i = 0; i < Find; i++){
		string Target;
		cin >> Target;
		//이름(키)로 값(value)확인
		if (Group[Target]) {
			Count++;
		}
	}
	cout << Count << "\n";
	return 0;
}    