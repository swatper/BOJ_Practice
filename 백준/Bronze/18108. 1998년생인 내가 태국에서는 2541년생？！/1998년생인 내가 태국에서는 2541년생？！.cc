#include <iostream>
using namespace std;

//클래스 생성
class Year_Of_AD {
public:
	int year;			//속성
	int N_To_Year();	//메서드
	Year_Of_AD(int A);	//생성자
};
//생성자 구현
Year_Of_AD::Year_Of_AD(int A) {
	year = A;
}
//메서드 구현
int Year_Of_AD::N_To_Year() {
	year = year - 543;
	return year;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	Year_Of_AD Object(N);	//객체생성
	cout << Object.N_To_Year() << "\n";
	return 0;
}