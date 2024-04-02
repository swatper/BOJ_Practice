#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string CroatiaWord;
	//크로아티아 문자열 배열
	string TransAlpha[8] = {"c=", "c-", "dz=", "d-", "lj" , "nj" , "s=" , "z="};
	cin >> CroatiaWord;

	for (int i = 0; i < 8; i++) {
		while (true){
			//크로아티아 문자 배열의 i번째 문자열이 find()함수를 통해 입력 받은 문자열 안에 있는지 확인
			if (CroatiaWord.find(TransAlpha[i]) != string::npos) {//있으면
				//CroatiaWord.find(TransAlpha[i])은 CroatiaWord전체 문자열에 TransAlpha[i] 문자열이 있는 가장 처음 위치를 반환
				CroatiaWord.replace(CroatiaWord.find(TransAlpha[i]),TransAlpha[i].length(), "?");
			}
			else {
				break;
			}
		}
	}
	cout << CroatiaWord.length() << "\n";
	return 0;
}