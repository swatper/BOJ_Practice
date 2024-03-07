#include <iostream>
//sqrt()을 사용하기위해 cmath 헤더파일을 불러옴
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	double D, H, W;
	int real_H, real_W;
	long double tmp;
	cin >> D >> H >> W;
	//피타고라스의 정리 (밑변^2 + 높이^2 = 빗변^2)
	tmp = D * D / (H * H + W * W);
	//sqrt()를 통해 제곱근을 구할 수 있음
	real_H = (int)(sqrt(tmp) * H);
	real_W = (int)(sqrt(tmp) * W);
	cout << real_H << " " << real_W << "\n";
}