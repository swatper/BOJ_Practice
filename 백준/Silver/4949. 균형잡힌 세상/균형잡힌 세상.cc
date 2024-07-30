#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true){
		string sentence;
		//stack을 이용하여 괄호의 짝이 맞는지 확인
		stack<char> bracket;
		//짝이 맞는지 표시할 변수
		bool isBalanced = true;
		//getline 함수를 이용하여 문장 \n전까지 입력 받기
		getline(cin , sentence);
		if (sentence == "."){
			break;
		}
		for (int i = 0; i < sentence.length(); i++){
			//'['나  '('가 들어오면 stack에 저장
			if (sentence[i] == '[' || sentence[i] == '('){
				bracket.push(sentence[i]);
			}

			if (sentence[i] == ')'){
				//stack이 비어있거나 짝이 안 맞으면
				if (bracket.empty() || bracket.top() != '('){
					isBalanced = false;
					break;
				}
				else {
					bracket.pop();
				}
			}

			if (sentence[i] == ']'){
				//stack이 비어있거나 짝이 안 맞으면
				if (bracket.empty() || bracket.top() != '[') {
					isBalanced = false;
					break;
				}
				else {
					bracket.pop();
				}
			}

		}
		//결과 확인
		if (isBalanced && bracket.empty()){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}