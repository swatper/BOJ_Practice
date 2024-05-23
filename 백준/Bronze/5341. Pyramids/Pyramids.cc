#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (true){
        int Num, Result = 0;
        cin >> Num;
        if (Num == 0)
        {
            break;
        }
        //피라미드 n층에 필요힌 블록의 수
        //= 1부터 n까지의 합
        Result = Num * (Num + 1) / 2;
        cout << Result << "\n";
    }
    return 0;
}