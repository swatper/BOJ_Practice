#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	deque<int> Deque;
	int Try, Command, Num;
	cin >> Try;
	for (int i = 0; i < Try; i++){
		cin >> Command;
		switch (Command)
		{
		case 1:
			cin >> Num;
			Deque.push_front(Num);
			break;
		case 2:
			cin >> Num;
			Deque.push_back(Num);
			break;
		case 3:
			if (Deque.empty()){
				cout << "-1\n";
			}
			else {
				cout << Deque.front() << "\n";
				Deque.pop_front();
			}
			break;
		case 4:
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.back() << "\n";
				Deque.pop_back();
			}
			break;
		case 5:
			cout << Deque.size() << "\n";
			break;
		case 6:
			if (Deque.empty()){
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
			break;
		case 7:
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.front() << "\n";
			}
			break;
		case 8:
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.back() << "\n";
			}
			break;
		}
	}
	return 0;
}