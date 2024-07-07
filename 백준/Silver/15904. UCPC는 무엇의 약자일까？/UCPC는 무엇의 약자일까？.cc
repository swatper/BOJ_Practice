#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string word, result = "";
	//string의 getline()을 사용하여 "\n"을 구분자 문자로
	//공백을 포함해서 입력 받기
	getline(cin, word);
	for (int i = 0; i < word.length(); i++){
		//UCCCPC의 경우 UCPC를 만들 수 있으나
		//기존의 방법인 대문자만 저장하면 UCCCPC가 되므로
		//반례가 발생하여 수정
		//-> 대문자를 순서대로 저장하도록 조건 추가
		if (word[i] == 'U' && result == "") {
			result += 'U';
		}
		else if (word[i] == 'C' && result == "U"){
			result += 'C';
		}
		else if (word[i] == 'P' && result == "UC"){
			result += 'P';
		}
		else if (word[i] == 'C' && result == "UCP"){
			result += 'C';
		}
	}
	//저장한 문자 상태 확인
	if (result == "UCPC"){
		cout << "I love UCPC\n";
	}
	else{
		cout << "I hate UCPC\n";
	}
	return 0;
}