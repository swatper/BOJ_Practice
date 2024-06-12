#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//포켓몬 이름으로 찾을 배열(?)
	map<string, int> PokemonDic1;
	//포켓몬 번호로 찾을 배열
	vector<string> PokemonDic2;
	int Pokemons, Problems;
	cin >> Pokemons >> Problems;
	for (int i = 1; i <= Pokemons; i++){
		string PokemonName;
		cin >> PokemonName;
		//포켓몬 사전에 원소 추가하기
		PokemonDic1.insert({ PokemonName, i});
		PokemonDic2.push_back(PokemonName);
	}
	//문제 맞추기(?)
	for (int i = 0; i < Problems; i++){
		string Problem;
		cin >> Problem;
		//포켓몬 번호를 입력 받았을 경우
		//아스키코드 65 이하면 번호를 입력 받은 것
		if (Problem[0] < 65) {
			//포켓몬의 이름 출력
			cout << PokemonDic2[stoi(Problem)- 1] << "\n";
		}
		//포켓몬 이름을 입력 받았을 경우
		else {
			//포켓몬의 번호(value) 출력
			cout << PokemonDic1[Problem] << "\n";
		}
	}
	cout << "\n";
	return 0;
}