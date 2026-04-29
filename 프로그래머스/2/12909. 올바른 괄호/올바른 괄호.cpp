#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
	stack<char> brackets;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(')
			brackets.push(i);
		else {
			if (brackets.empty()) {
				answer = false;
				break;
			}
			brackets.pop();
		}
	}
	if (!brackets.empty())
		answer = false;

    return answer;
}