#include <iostream>
using namespace std;

int main() {
	int H = 0;
	int M = 0;
	int Time;
	cin >> H >> M>> Time;
	M = M+ Time;
	if (M >= 60) {//60분을 넘기면
		H = H + (M / 60);	//시간 추가
		M = M % 60;			//시간을 올린 나머지 분
	}
	if (H >= 24) {//24시간을 넘기면
		H = H % 24;
	}
	cout << H << " " << M << endl;
}