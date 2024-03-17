#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true){
		bool is_palindrome = true;
		string Num;
		cin >> Num;
		//0이 입력되면 멈추기
		if (Num == "0") { break; }
		int front_index = 0;
		int back_index = Num.size() - 1;
		while (front_index <= back_index){
			//양 끝의 숫자가 같은지 비교
			if (Num[front_index] == Num[back_index]) {
				//같으면 앞 뒤 숫자를 한 칸씩 옮김
				front_index++;
				back_index--;
			}
			else {
				//다르면 팰린드롬 수가 아님
				is_palindrome = false;
				break;
			}
		}
		if (is_palindrome){
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
	return 0;
}