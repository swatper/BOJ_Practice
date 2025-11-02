#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int students, ticket, curNum = 1;
	stack<int>watingLine;		//대기줄
	cin >> students;
	for (int i = 0; i < students; i++){
		cin >> ticket;
		if (curNum == ticket)
			curNum++;
		//현재 온 사람이 줄 수 없는 사람이면 대기줄로 보냄
		else {
			watingLine.push(ticket);
			continue;
		}
		//대기줄 확인
		while (!watingLine.empty()) {
			if (curNum == watingLine.top()) {
				watingLine.pop();
				curNum++;
			}
			else
				break;
		}
	}

	if (watingLine.empty())
		cout << "Nice" << '\n';
	else
		cout << "Sad" << '\n';
	return 0;
}
