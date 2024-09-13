#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//알파벳 a~z 26자를 이용하여 26진수 사용하기
	unsigned long A, B, ResultType2 = 0;
	string C, ResultType1 = "aaaaaaaaaaaaa";
	int Type;
	cin >> Type;

	//10진수 to 26진수
	if (Type == 1) {
		cin >> A >> B;
		unsigned long temp = A + B;

		for(int i = ResultType1.length() - 1; i >=0 ; i--){

			if (temp <= 0){
				break;
			}

			ResultType1[i] = (char)((temp % 26) + 'a');
			temp /= 26;
		}

		cout << ResultType1 << "\n";
	}

	//26진수 to 10진수
	else if(Type == 2){
		cin >> C;
		unsigned long temp = 1;

		for (int i = C.size() - 1; i >= 0; i--){
			ResultType2 += temp * (C[i] - 'a');
			temp *= 26;
		}

		cout << ResultType2 << "\n";
	}
	return 0;
}