#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C, result = 0;
	string charnum;
	
	cin >> A >> B >> C;

	//A B를 문자로 바꾸서 문자열 합치기
	charnum = to_string(A) + to_string(B);
	result = stoi(charnum) - C;

	cout << A + B - C << "\n";
	cout << result << "\n";

	return 0;
}
