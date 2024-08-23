#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, Length, Weight = -1;
	cin >> N;
	vector<int> Ropes;
	for (int i = 0; i < N; i++){
		cin >> Length;
		Ropes.push_back(Length);
	}
	//오름차순 정렬
	sort(Ropes.begin(), Ropes.end());

	//계산
	//가장 중량이 작은 로프 * (작은 로프보다 큰 로프의 갯수 + 1) = Weight가 가장 큰 값 찾기
	for (int i = 0; i < N; i++){
		Weight = (Weight > (Ropes[i] * (N - i))) ? Weight : (Ropes[i] * (N - i));
	}
	cout << Weight << "\n";
	return 0;
}