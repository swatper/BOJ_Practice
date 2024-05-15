#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int InputNum, Result = 0;
    for (int i = 0; i < 5; i++){
        cin >> InputNum;
        //제곱한 수를 더함
        Result += InputNum * InputNum;
    }
    cout << Result % 10 << "\n";
    return 0;
}