#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string result; //폴리오미노로 덮을 string 문자열 변수
	string board;
	cin >> board;
	int check = 0;
	int error = 0;

	//폴리오노마 풀이과정
	//1. '.'나 '\n'를 기준으로 X의 개수를 check++
	//2. 개수를 세다가 check가 4가되면 "AAAA"로 덮고 4로 나눈 나머지를 check에 저장
	//-> '.'전까지 전체 길이에서 4의 배수만큼 "AAAA"로 덮게 됨
	//3. 4로 나눈 나머지 값에서 홀수면 "BB"로 덮을 수 없으므로 -1을 출력
	//-> 4로 나눈 나머지가 2면 "BB"로 덮게 됨
	
	//입력받은 board의 크기만큼 반복
	for (int i = 0; i < board.size(); i++) {
		//'.'전까지 문자의 'X'의 갯수 세기
		if (board[i] == 'X') {
			check++;
		}
		//'X'의 갯수가 4가되면
		//폴리오미노 추가
		if (check == 4) {
			//c++의 string 클래스는 + 연산자를 이용해 문자열을 추가할 수 있음
			result += "AAAA";
			check = check % 4;
		}
		//'.'로 끝나거나 단어의 끝에 도달할 경우
		if (board[i] == '.' || (i + 1) == board.size()) {
		//i+1을 하게된 이유는 단어의 끝을 확인하기 위함

			//'X'의 개수가 홀수면 덮을 수 없음
			if (check %2 == 1 ) {
				error++;
				break;
			}
			//check가 2고 .이나 단어의 끝부분이면 마지막 문자열인 "BB" 추가
			if(check == 2) {
				result += "BB";
			}
			if (board[i] == '.' ) {
				result += '.';
			}
			//'.'전까지의 문자열을 확인했으니 다음 문자열을 확인하기 위해 check를 초기화
			check = 0;
		}
	}
	if (error > 0) {
		cout << -1 << "\n";
	}
	else {
		cout << result << "\n";
	}
	return 0;
}