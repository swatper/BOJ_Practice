#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0; i < Tc; i++){
		vector<char> result;
		stack<char> passWord, Temp;
		string keyLog;
		cin >> keyLog;
		for (int j = 0; j < keyLog.size(); j++) {
			if (keyLog[j] == '-'){
				if (passWord.empty()) {
					continue;
				}
				passWord.pop();
			}
			else if (keyLog[j] == '<') {
				//커서가 뒤로 이동하면 이동한 만큼 passWord에서 단어를 제거
				//제거한 단어는 임시 저장
				if (passWord.empty()){
					continue;
				}
				Temp.push(passWord.top());
				passWord.pop();
			}
			else if (keyLog[j] == '>') {
				//커서가 앞으로 이동하면 이동한 만큼 임시 저장한 temp에서 단어를 제거
				//제거한 단어는 passWord에 저장
				if (Temp.empty()){
					continue;
				}
				passWord.push(Temp.top());
				Temp.pop();
			}
			else {
				passWord.push(keyLog[j]);
			}
		}
		//임시로 저장한 문자들 저장
		while (!Temp.empty()) {
			passWord.push(Temp.top());
			Temp.pop();
		}
		//stack에 저장된 문자 뒤집기
		while (!passWord.empty()){
			result.push_back(passWord.top());
			passWord.pop();
		}
		for (int k = result.size() - 1; k >= 0; k--){
			cout << result[k];
		}
		cout << "\n";
	}
	return 0;
}    