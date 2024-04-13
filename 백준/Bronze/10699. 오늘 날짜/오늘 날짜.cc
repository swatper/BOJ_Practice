#define _CRT_SECURE_NO_WARNINGS //보안상 localtime은 오류 발생
#include <iostream>
#include <ctime> //시간 함수 사용
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//현재 시간 가져오기
	time_t CurrentTime = time(0);
	//구조체 사용
	struct tm* TimeStruct = localtime(&CurrentTime);
	//1900년 1월 1일 이후로 시간을 계산되어있음
	cout << TimeStruct->tm_year + 1900 << "-";
	cout.width(2);
	cout.fill('0');
	cout << TimeStruct->tm_mon + 1 << "-";
	cout.width(2);
	cout.fill('0');
	cout << TimeStruct->tm_mday << "\n";
	return 0;
}