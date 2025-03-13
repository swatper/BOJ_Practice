#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int count = 0;
	string sentence;
	//getline 함수를 통해 '\n'전까지 입력 받기
	getline(cin, sentence);

	if (sentence.size() == 1 && sentence[0] == ' ') {
		cout << 0 << "\n";
		return 0;
	}

	//공백 기준으로 단어 갯수 계산하기
	for (int i = 0; i < sentence.size() - 1; i++){
		if (sentence[i] == ' ' && i != 0 && i != sentence.size() - 1)
			count++;
	}
	
	cout << count + 1 << "\n";
	return 0;
}
