#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	long N, T, S, I, C, waitTime;
	long pastBusTime = 2147483647; 
	waitTime = -1;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> S >> I >> C;
		//도착 예정 시간이 마지막 버스의 도착 시간보다 크면 버스 못 탐
		if (T <= S + I * (C-1)) {
			//이분 탐색 
			long L = 0;
			long R = C;
			while (L <= R) {
				long mid = (L + R) / 2;
				if (T > S + I * mid) {
					L = mid + 1;
				}
				else {
					//기다리는 시간 계산
					//n번째 버스를 탈 때 기다리는 시간 계산
					waitTime = (S + I * mid) - T;
					//과거 버스를 탈 때 기다리는 시간과 비교하여 가장 작은 값 입력
					waitTime = (waitTime < pastBusTime) ? waitTime : pastBusTime;
					//앞에서 구한 가장 작은 값을 과거 버스의 시간으로 저장
					pastBusTime = waitTime;
					R = mid - 1;
				}
			}
		}
	}
	cout << waitTime << "\n";
	return 0;
}