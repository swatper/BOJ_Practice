#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string words[5];
	for (int i = 0; i < 5; i++){
		cin >> words[i];
	}

	//j번째 있는 단어의 i번째 문자 출력
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 5; j++){
			//j번째 단어의 길이 확인
			if (words[j].length() > i){
				cout << words[j][i];
			}
		}
	}
	
	return 0;
}