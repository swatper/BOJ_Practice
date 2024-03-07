#include <iostream>
using namespace std;

class Calculate {//클래스
public:
	int a;//속성
	int b;//속성
	void result();//메서드 선언
	Calculate(int x, int y);//생성자
};

Calculate::Calculate(int x, int y) {//생성자 구현
	a = x;
	b = y;
}
void Calculate::result() {//메서드 구현
	int c;
	c = a - b;
	cout << c << endl;
}

int main() {
	int N1, N2;
	cin >> N1 >> N2;
	Calculate Cal(N1, N2);//객체 생성
	Cal.result();
}