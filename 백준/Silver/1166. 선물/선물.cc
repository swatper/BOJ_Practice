#include <iostream>
#define MAX 1000000000
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long N, L, W, H;
	double Size;
	cin >> N >> L >> W >> H;
	//이분 탐색 시작
	double Left = 0, Right = MAX;
	//실수로 계산하고 정수로 비교하기 때문에
	//while문 사용 시 무한반복하기 때문에
	//for문을 이용하여 반복하는 횟수를 제한
	for (int i = 0; i < 100; i++) {
		double Mid = (Left + Right) / 2;
		//특정 길이로 상자의 크기를 설정하였을 때, 들어갈 수 있는 상자 수 구하기
		long long Presents = ((long long)(L / Mid) * (long long)(W / Mid) * (long long)(H / Mid));
		//넣으려는 상자의 갯수와 앞에서 구한 상자의 갯수를 비교
		if (Presents >= N){
			Left = Mid;
			Size = Mid;
		}
		else{
			Right = Mid;
		}
		//cout << Left << " " << Right << " " <<  Mid << "\n";
	}
	//자리 고정
	cout << fixed;
	//유효 숫자 20(오차)
	cout.precision(20);
	cout << Size << "\n";
	return 0;
}