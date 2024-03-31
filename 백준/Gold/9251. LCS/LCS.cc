#include <iostream>
using namespace std;
//배열이 너무 크기때문에
//C++의 main에서 돌릴 수 없어서
//전역 변수로 선언하여 사용
int Array[1001][1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string WordA, WordB;
	cin >> WordA >> WordB;
	Array[0][0] = 0;
	//각 문자열의 문자들을 가로, 세로로 나열(각 문자가 연속일 필요가 없음)
	for (int i = 1; i <= WordA.size(); i++) {
		for (int j = 1; j <= WordB.size(); j++) {
			//문자열 A와 B의 각 문자를 서로 비교하여 같은지 다른지 확인
			if (WordA[i - 1] == WordB[j - 1]) {
				//문자가 같은 경우, 이전 문자의 부분 수열 값을 1 증가 시킴
				Array[i][j] = Array[i-1][j-1] + 1;
			}
			else
			{
				Array[i][j] = Array[i - 1][j] > Array[i][j - 1] ? Array[i - 1][j] : Array[i][j - 1];
			}
		}
	}
	cout << Array[WordA.size()][WordB.size()] << "\n";
	return 0;
}