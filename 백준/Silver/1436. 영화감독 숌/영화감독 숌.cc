#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numbering, numOfMovie = 665;
	cin >> numbering;
	//n번째 영화까지 반복
	for (int i = 0; i < numbering; i++){
		while (true){
			numOfMovie++;
			//i번째 영화의 제목에 연속된 666이 포함되었으면
			if ((to_string(numOfMovie).find("666"))!= string::npos) {
				//i번쨰 영화의 제목 부여(while문 종료)
				break;
			}
		}
	}
	cout << numOfMovie << "\n";
	return 0;
}