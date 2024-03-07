#include <iostream>
using namespace std;

class calculate {
private :
	int N1, N2;
public:
	int ADD();
	calculate(int a,int b);
};
calculate::calculate(int a,int b) {
	N1 = a;
	N2 = b;
}
int calculate::ADD() {
	int tmp;
	tmp = N1 + N2;
	return tmp;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true){
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0) {
			break;
		}
		calculate cal(A,B);
		cout << cal.ADD() << "\n";
	}
	return 0;
} 