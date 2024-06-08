#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Size, Num = 1;
	//연산 과정을 저장할 변수
	vector<string> Try;
	bool Flag = true;
	stack<int> CurrntStack;
	cin >> Size;
	for (int i = 0; i < Size; i++) {
		int Trarget;
		cin >> Trarget;
		//Num값을 제일 위로 올려서 해당 숫자가 target값인지 확인하면
		//수열을 생성 여부를 알 수 있음
		while (Num <= Trarget){
			CurrntStack.push(Num);
			Try.push_back("+");
			Num++;
		}
		//Target의 값과 현재 스택의 맨 위 값과 같으면
		if (CurrntStack.top() == Trarget) {
			//현재 스택의 맨 위 값을 pop해서 해당 값을
			//수열에 추가할 수 있음
			CurrntStack.pop();
			Try.push_back("-");
		}
		//다르면 
		else {
			//Target값이 작아 현재 스택의 중간에 있는 값을 요구하므로
			//해당 값을 수열에 추가할 수 없음
			Flag = false;
			break;
		}
	}
	if (Flag){
		for (int i = 0; i < Try.size(); i++){
			cout << Try[i] + "\n";
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}