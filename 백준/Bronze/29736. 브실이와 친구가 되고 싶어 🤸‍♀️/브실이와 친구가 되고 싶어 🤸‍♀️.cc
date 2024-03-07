#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A, B, K, X;
	int friends = 0 ; 
	cin >> A >> B >> K >> X;
	int h = K + X; //친구가 될 수 있는 최소한으로 맞춰야하는 문제의 수
	int l = K - X; //친구가 될 수 있는 최대한으로 맞춰야하는 문제의 수
	//친구가 가능한 사람의 수 계산
	if (h < A || l > B) { //최솟값이 B보다 크거나 최솟값이 A보다 작으면
		cout << "IMPOSSIBLE\n";	 //친구를 사귈 수 없음
	}
	else{
		//친구가 될 수 있는 범위를 설정
		//브실이 기준으로 친구가 될 수 있는 범위(h~K)와
		//사람들의 범위 (A~B)의 곂치는 구간의 크기를 구함
		int start, end;
		if (A >= l) {		//최솟값이 A보다 작으면 
			start = A;		//A부터 시작 
		}
		else  if (A <= l) { //최솟값이 A보다 크면
			start = l;		//최솟값부터 시작
		}
		if (B >= h) {		//최댓값이 B보다 작으면
			end = h;		//최댓값부터 시작
		}
		else if (B <= h) {	//최댓값이 B보다 크면
			end = B;		//B부터 시작
		}

		for (int i = start; i <= end; i++) {
			friends++;
		}
		cout << friends << "\n";
	}
	return 0;
} 