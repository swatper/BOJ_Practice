#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	int weight = 0;
	int price = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int W, H, L, fruits;
		string fruit_type;
		cin >> fruit_type >> W >> H >> L;
		if (fruit_type == "A") {
			W = W / 12;						//사과를 가로로 넣었을 때 들어갈 수 있는 사과의 수(가로)
			L = L / 12;						//사과를 세로로 넣었을 때 들어갈 수 있는 사과의 수(세로)
			H = H / 12;						//사과를 쌓았을 때 들어갈 수 있는 사과의 갯수(높이)
			fruits = W * L * H;				//상자안에 사과가 들어가는 갯수 (가로 * 세로 * 높이)
			weight += 1000 + fruits * 500;  //상자 하나의 무게 + 사과의 갯수 * 500
			price += fruits * 4000;			//사과의 갯수 * 4000

		}
		else
		{
			weight += 6000;					//배는 크기에 상관없이 무조건 6000
		}
	}
	cout << weight << "\n" << price << "\n";
	return 0;
} 