#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//매팽 연습 12
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, int> Animals;
	int numOfAnimals;
	cin >> numOfAnimals;
	for (int i = 0; i < numOfAnimals; i++){
		string name;
		cin >> name;
		//문자열을 정렬 시키기
		sort(name.begin(), name.end());
		//key가 없으면 자동으로 추가
		Animals[name]++;
	}
	cout << Animals.size() << "\n";
	return 0;
}