#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int J, N;
	int Can_Solve = 0;
	cin >> J >> N;
	//getline에서 cin 사용 시 마지막 '\n'은 저장하지 않고 버퍼에 남음
	//-> 다음 입력받을 떄 '\n'이 있으므로 입력받지 못하기 때문에 
	//ignore을 통해 버퍼를 비워줘야 함
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string Problem;
		int Problem_size = 0;

		//getline함수를 통해 공백을 포함해서 문자열 받기
		getline(cin, Problem);

		//문자열의 각 문자를 아스키코드 값으로 비교하며 진행
		for (int j = 0; j < Problem.size(); j++) {
			//아스키코드값이  48이상 57이하면 0~9를 의미함
			//97 이상 122이하면 알파벳 a부터 z까지 소문자를 의미함
			if ((Problem[j] >= '0' && Problem[j] <= '9') || (Problem[j] >= 'a' && Problem[j] <= 'z')) {
				Problem_size += 2;
				/*cout << Problem[j] << "\n";
				cout << "소문자/숫자\n";*/
			}
			//아스키코드값이 65 이상 90이하면 알파벳 A부터 Z까지 대문자를 의미함
			if (Problem[j] >= 'A' && Problem[j] <= 'Z') {
				Problem_size += 4;
				/*cout << Problem[j] << "\n";
				cout << "대문자\n";*/
			}
			//공백이면
			if (Problem[j] == ' ') {
				Problem_size += 1;
				/*cout << Problem[j] << "\n";
				cout << "공백\n";*/
			}
		}
		//cout << Problem_size << "\n";
		if (Problem_size <=J) {
			Can_Solve++;
		}
	}
	cout << Can_Solve << "\n";
	return 0;
}