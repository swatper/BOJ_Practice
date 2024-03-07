#include <iostream>
#include <string>
#define MAX 2147483647 //(2^31) - 1
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int lan_wires, req_lan_wires;
	//랜선의 최대 길이
	long length = 0;
	cin >> lan_wires >> req_lan_wires;
	long *lan_wires_length = new long [lan_wires];
	//각 랜선의 길이 입력받아 배열에 저장
	for (int i = 0; i < lan_wires; i++) {
		cin >> lan_wires_length[i];
	}
	//이분탐색
	long L = 1;
	long long H = MAX;	
	while (L <= H) {
		unsigned long long mid = (L + H) / 2;
		int cut_wires = 0;
		for (int i = 0; i < lan_wires; i++) {
			//특정 길이로 잘랐을때의 만들어지는 랜선의 수
			cut_wires += lan_wires_length[i] / mid;
		}
		//잘랐을때 만들어지는 랜선의 수와 필요한 랜선의 수를 비교
		if (req_lan_wires > cut_wires) {
			H = mid - 1; 
		}
		else {
			//랜선의 최대 길이를 저장
			length = mid;
			L = mid + 1;
		}
	}
	cout << length << "\n";
	return 0;
}
