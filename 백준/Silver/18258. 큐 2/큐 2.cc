#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Try, Num;
	string Command;
	queue<int> Q;
	cin >> Try;
	for (int i = 0; i < Try; i++){
		cin >> Command;
		//C#이면 switch문 사용했을텐데....
		if (Command == "push") {
			cin >> Num;
			Q.push(Num);
		}
		else if (Command == "pop") {
			if (Q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << Q.front() << "\n";
			Q.pop();
		}
		else if (Command == "size") {
			cout << Q.size() << "\n";
		}
		else if (Command == "empty") {
			cout << Q.empty() << "\n";
		}
		else if (Command == "front") {
			if (Q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << Q.front() << "\n";
		}
		else if (Command == "back") {
			if (Q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << Q.back() << "\n";
		}
	}
	return 0;
}