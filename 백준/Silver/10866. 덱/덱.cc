#include <iostream>
#include <deque>
using namespace std;

int main() { 
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	deque<int> dq;
	int Cmds, Num;
	string Cmd;
	cin >> Cmds;
	for (int i = 0; i < Cmds; i++) {
		cin >> Cmd;
		if (Cmd == "push_front") {
			cin >> Num;
			dq.push_front(Num);
			continue;
		}
		if (Cmd == "push_back") {
			cin >> Num;
			dq.push_back(Num);
			continue;
		}
		if (Cmd == "pop_front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			continue;
		}
		if (Cmd == "pop_back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			continue;
		}
		if (Cmd == "size") {
			cout << dq.size() << "\n";
			continue;
		}
		if (Cmd == "empty") {
			if (dq.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
			continue;
		}
		if (Cmd == "front") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else{
				cout << dq.front() << "\n";
			}
			continue;
		}
		if (Cmd == "back") {
			if (dq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
			}
			continue;
		}
	}
	return 0;
}