#include <iostream>
using namespace std;
class Compairson {
public:
	int a, b;
	Compairson(int x, int y);
	void Result();
};
Compairson::Compairson(int x, int y) {
	a = x;
	b = y;
}
void Compairson::Result() {
	if (a > b) {
		cout << ">" << "\n";
	}
	if (a == b) {
		cout << "==" << "\n";
	}
	if (a < b) {
		cout << "<" << "\n";
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;
	Compairson Comp(A,B);
	Comp.Result();
	return 0;
}
