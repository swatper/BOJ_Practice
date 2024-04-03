#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int index;
	string Grade;
	//학점 배열
	string Grades[13] = { "A+" , "A0" , "A-",
						 "B+" , "B0" , "B-",
						 "C+" , "C0" , "C-",
						 "D+" , "D0" , "D-",
						 "F" };
	//학점에 대한 점수 배열(학점 배열과 점수 배열을 1:1 매칭 시킴)
	string Socre[13] = { "4.3" , "4.0" , "3.7",
						 "3.3" , "3.0" , "2.7",
						 "2.3" , "2.0" , "1.7",
						 "1.3" , "1.0" , "0.7",
						 "0.0" };
	cin >> Grade;
	for (int i = 0; i  < 13; i++) {
		//입력 받은 학점이 배열에 어디 위치하는지 확인
		if (Grade == Grades[i]) {
			index = i;
			break;
		}
	}
	//해당 위치에 있는 점수 배열 값을 출력
	cout << Socre[index] << "\n";
	return 0;
}