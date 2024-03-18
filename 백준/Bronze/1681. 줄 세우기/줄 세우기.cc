#include <iostream>
#include <string>
using namespace std;


int main() {
	//속도를 향상시키기 위한 코드
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Students, N = 0;
	//피해야 할 라벨 번호를 string으로 입력 받기
	string Label, Num;
	//값 입력 받기
	cin >> Students >> Label;

	//학생들에게 라벨 부여하기
	for (int i = 0; i < Students;) {
		N++;
		//학생에게 부여할 라벨 번호 N을 문자열로 변환
		string tmp = to_string(N);
		//변환된 문자열에서 string의 find() 함수를 통해 Label이 있는지 확인
		if (tmp.find(Label) != string::npos) {
			//있으면 번호를 부여할 수 없으므로 다시 반복
			continue;
		}
		else {
			//없으면 학생에게 라벨 번호 부여
			Num = to_string(N);
			//라벨 번호를 부여 받은 학생들의 수 증가
			i++; 
		}
	}
	cout << Num + "\n";
	return 0;
}