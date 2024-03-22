#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	string Bracket;
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		cin >> Bracket;
		//스텍 생성
		stack<string> Bracketstack;
		bool isOK = true;
		for (int j = 0; j < Bracket.size(); j++) {
			//(를 만나면 스텍에 ( 문자 추가
			if (Bracket[j] == '(') {
				Bracketstack.push("(");
			}
			//)를 만나면 스텍에 (문자를 하나씩 지움
			else {
				//만약 스텍이 비어있는데 )문자를 만나면 괄호의 짝이 안 맞음
				if (Bracketstack.empty()) {
					isOK = false;
					break;
				}
				Bracketstack.pop();
			}
		}
		//스텍이 비어있지 않으면 (가 남아있으므로 괄호의 짝이 안 맞음
		if (isOK && Bracketstack.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}