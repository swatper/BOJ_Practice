#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Cmds;
	string File_name;		//맨 처음 파일 이름을 저장할 string
	cin >> Cmds;			//파일 갯수 입력받기

	//맨 처음 입력된 파일의 문자열의 문자와 두 번째부터 입력되는 문자열의 문자를
	//같은 위치에 있는 문자를 서로 비교하며 같으면 그대로 두고 다르면
	//처음 입력된 문자열의 문자를 '?'로 바꿈
	for (int i = 0; i < Cmds; i++) { //파일이름 입력받기
		string Add_File;
		if (i == 0) {			//맨 처음 파일 이름 입력받기  
			cin >> File_name;
			continue;			//continue를 이용해 아래의 나머지 코드를 생략하고 for문으로 돌아옴
		}
		cin >> Add_File;		//n번째 파일 이름 받기
		for (int j = 0; j < File_name.length(); j++) {  //문자열의 길이만큼 반복
			if (File_name[j] == Add_File[j]) {			//문자가 같으면
				continue;
			}
			else {									//문자가 다르면
				File_name[j] = '?';					//?를 저장
			}
		}
	}
	cout << File_name << "\n";
	return 0;
}