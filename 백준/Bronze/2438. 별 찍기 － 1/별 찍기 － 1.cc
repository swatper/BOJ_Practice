#include <iostream>
using namespace std;

class Stars {
	int Stars_N;
public:
	Stars(int a);
	void Draw();

};
Stars::Stars(int a) {
	Stars_N = a;	//private여도 객체에서 안에서 접근했기 떄문에 사용 가능
}

void Stars::Draw() {
	for (int i = 1; i <= Stars_N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int stars;
	cin >> stars;
	Stars ST(stars);
	ST.Draw();
	return 0;
}