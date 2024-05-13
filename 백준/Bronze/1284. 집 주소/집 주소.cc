#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (true){
        int Size = 0;
        string RoomNumber;
        cin >> RoomNumber;
        if (RoomNumber == "0") {
            break;
        }
        //각 문자를 공백 + 문자 형태로 생각하여 문자의 크기에 공백 1개를 추가
        //-> 각 문자의 크기 + 1(공백)
        for (int i = 0; i < RoomNumber.length(); i++){
            if (RoomNumber[i] == '1' ) {
                Size += 3;
            }
            else if (RoomNumber[i] == '0') {
                Size += 5;
            }
            else{
                Size += 4;
            }
        }
        //맨 마지막 공맥 추가
        cout << Size + 1 << "\n";
    }
    return 0;
}