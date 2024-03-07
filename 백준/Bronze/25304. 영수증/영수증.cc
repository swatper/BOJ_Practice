#include <iostream>
using namespace std;

class Receipt {
private:
	int Price, nums;
	int total = 0;
public:
	Receipt();
	void result(int a, int b);
	int getter();
};
Receipt::Receipt() {} //기본생성자
void Receipt::result(int a, int b) {
	this->Price = a;
	this->nums = b;
	this->total = this->total + Price * nums;
}
int Receipt:: getter() {
	return total;
}

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Receipt Re;
	int X, N;
	cin >> X ;
	cin >> N;
	for (int i = 1; i <= N;i++) {
		int price, nums;
		cin >> price >> nums;
		Re.result(price, nums);
	}
	if (Re.getter() == X) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}