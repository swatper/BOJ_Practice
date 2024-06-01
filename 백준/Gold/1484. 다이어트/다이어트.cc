#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int G;
    cin >> G;
    long long Front = 1;
    long long Back = 1;
    //존재 여부 확인
    bool IsExist = false;
    //탐색 시작
    while (Back < G){
        //몸무게 찾기
        long long TempG = (Back * Back) - (Front * Front);
        if (TempG == G){
            IsExist = true;
            cout << Back << "\n";
        }
        if (TempG > G){
            Front++;
        }
        else{
            Back++;
        }
    }
    if (!IsExist){
        cout << "-1\n";
    }
    return 0;
}
