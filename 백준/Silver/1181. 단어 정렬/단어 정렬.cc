#include <iostream>
#include <string>
//정렬 알고리즘을 쓰기위한 헤더
#include <algorithm>
using namespace std;


//정렬 기준
bool Sorting(string a, string b) {
	//만약 길이가 같으면 알파벳의 오름차순(<)으로 정렬 
	if (a.length() == b.length()) {
		return a < b;
	}
	//길이가 다르면 길이 순서대로 오름차순(<)으로 정렬
	else {
		return a.length() < b.length();
	}
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	string* Words = new string[N];

	//입력된 단어들 입력
	for (int i = 0; i < N; i++) {
		cin >> Words[i];
	}
	//sort 알고리즘 사용
	//sort(시작지점,끝지점,기준(bool))
	//만약 bool이 false면 자리를 바꿈
	sort(Words, Words + N, Sorting);

	//입력된 단어들 출력
	for (int i = 0; i < N; i++) {
		//중복 제거
		if (Words[i] != Words[i+1])
		{
			cout << Words[i] << "\n";
		}
	}
	return 0;
}