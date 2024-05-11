#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string MachineCode;
    int ParaMeter = 0, NumOfNOP = 0;
    //머신 코드 입력 받기
    cin >> MachineCode;
    //코신 코드 분석
    for (int i = 0; i < MachineCode.length(); i++){
        //명령어인지 파라미터인지 확인
        if (MachineCode[i] < 'a') {
            NumOfNOP += (4 - (ParaMeter % 4)) % 4;
            ParaMeter = 0;
           
        }
        //파라미터 갯수 세기
        ParaMeter++;
    }
    cout << NumOfNOP << "\n";
    return 0;
}