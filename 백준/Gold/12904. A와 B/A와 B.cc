#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string S, T;
	cin >> S >> T;
	//S를 T로 만드는 것 보다는 T를 S로 만드는 것이 쉬움
	//T의 길이가 S의 길이와 같아질 때까지 반복
	while (S.length() < T.length()){
		//T의 맨 마지막 문자가 A면 그 문자 지움
		if (T[T.length() - 1] == 'A') {
			T.pop_back();
		}
		//S에 B를 추가하려면, 문자열을 뒤집고 B를 추가하기 때문에,
		//T는 반대로 B를 삭제하고 뒤집으면 됨
		else {
			T.pop_back();
			reverse(T.begin() ,  T.end());
		}
	}
	if (S == T){
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
	return 0;
}