#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string Word;
    while(1){
        //공백도 받아야 하므로 getline을 이용해서 한 줄씩 입력 받음
        getline(cin, Word);
        //EOF는 End of File로 파일의 끝을 의미 -> 아무것도 안 받음
        if(cin.eof()){
            break;
        }
        cout << Word << "\n";
    }
	return 0;
}