#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int main() {
	int yyyy, mm, dd;
	scanf("%d-%d-%d", &yyyy, &mm, &dd);
	int N;
	scanf("%d",&N);
	//일
	int a = N % 30;
	dd += a;
	if (dd > 30) {
		//30일을 넘으면 1달을 추가
		mm = mm + (dd / 30);
		dd = dd % 30;
	}
	//개월
	N = N / 30;
	int b = N % 12;
	mm += b;
	if (mm > 12) {
		//12월을 넘으면 1년 추가
		yyyy = yyyy + (mm / 12);
		mm = mm % 12;
	}
	yyyy += N / 12;
	printf("%d-%02d-%02d\n", yyyy, mm, dd); //%0nd-> d값을 n자리수로 표현 
	return 0;
}