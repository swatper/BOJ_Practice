#include <iostream>
#include <string>
using namespace std;

int main() {
	string JaeHwan, Doc;
	cin >> JaeHwan >> Doc;
	if (JaeHwan.size()>=Doc.size()) {
		cout << "go\n";
	}
	else{
		cout << "no\n";
	}
	return 0;
}