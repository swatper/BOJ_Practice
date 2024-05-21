#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int Tc;
    string Text;
    cin >> Tc;

    //버퍼에 남아있는 내용 제거
    cin.ignore();

    for (int i = 1; i <= Tc; i++){
        //string의 getline()함수를 이용하여 '\n'을 구분자 문자로하여 입력받음
        getline(cin, Text);
        cout << i << ". " << Text << "\n";
    }

    return 0;
}