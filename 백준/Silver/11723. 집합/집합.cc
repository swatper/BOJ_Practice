#include <iostream>
#include <map>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, num;
	string command;
	cin >> N;
	map<int, bool> S;
	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command == "add"){
			cin >> num;
			S.insert({num, true});
		}
		if (command == "check") {
			cin >> num;
			if (S.find(num) == S.end()) {
				cout << 0 << "\n";
				continue;
			}
			cout << 1 << "\n";

		}
		if (command == "remove") {
			cin >> num;
			S.erase(num);

		}
		if (command == "toggle") {
			cin >> num;
			if (S.find(num) != S.end()) {
				S.erase(num);
				continue;
			}
			S.insert({num, true});

		}
		if (command == "all") {
			for (int i = 1; i <= 20; i++ ) {
				S.insert({i, true});
			}
		}
		if (command == "empty") 
			S.clear();
	}

	return 0;
}
