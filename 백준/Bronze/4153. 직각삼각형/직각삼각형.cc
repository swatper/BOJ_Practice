#include <iostream>
using namespace std;

class Triangle {
public:
	double x, y, z;							//속성 선언
	void distinction();						//메서드 선언
	Triangle(double a, double b, double c);//생성자 선언
};
void Triangle::distinction() {//메서드 구현
	double A = x * x; //각 변을 제곱
	double B = y * y;
	double C = z * z;
	if (A + B == C || B + C == A || C + A == B) { //두 변의 제곱하고 더한 값이  나머지 한 변의 제곱한 값과 다르면
		cout << "right" << "\n";
	}
	else{
		cout << "wrong" << "\n";
	}
}
Triangle::Triangle(double a, double b, double c) { //생성자 구현
	x = a;
	y = b;
	z = c;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c== 0){
			break;
		}
		Triangle Tri(a, b, c); //객체 생성
		Tri.distinction();
	}
}