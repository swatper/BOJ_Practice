#include <iostream>
using namespace std;

int Y_Payment(int a); //영식 요금제 계산 함수
int M_Payment(int a); //민식 요금제 계산 함수

int main() {
	cin.tie(NULL); //cin 과 cout을 풀어줌 ->버퍼를 지우는 과정 생략 -> 속도가 빨라짐
	ios_base::sync_with_stdio(false); //C 와 C++을 분리 -> 속도가 빨라짐

	int Ymoney = 0;				//영식 요금제를 이용했을 때의 비용
	int Mmoney = 0;				//민식 요금제를 이용했을 때의 비용
	int N;						//사용 횟수를 저장하는 변수
	cin >> N;					//사용 횟수 입력받기

	//각 요금제를 이용했을 때 요금이 얼마가 나오는지 계산 
	for (int i = 1; i <= N; i++) { //사용 횟수만큼 반복
		int Time;		//사용 시간 입력받기
		cin >> Time;
		Ymoney += Y_Payment(Time);	//영식 요금제의 비용 계산
		Mmoney += M_Payment(Time);	//민식 요금제의 비용 계산
	}
	//각 요금제의 비용을 비교
	if (Ymoney < Mmoney) {
		cout << "Y " << Ymoney << "\n";
	}
	else if(Ymoney == Mmoney){
		cout << "Y M " << Mmoney << "\n";
	}
	else {
		cout << "M " << Mmoney << "\n";
	}
	return 0;
}
int Y_Payment(int a) {
	int fee;					//요금제 사용 비용
	fee = ((a / 30) + 1) * 10;	//한번은 이용하므로 나눈 몫에 +1
	return fee;					//비용 반환
}
int M_Payment(int a) {
	int fee;					//요금제 사용 비용
	fee = ((a / 60) + 1) * 15;	//한번은 이용하므로 나눈 몫에 +1
	return fee;					//비용 반환
}