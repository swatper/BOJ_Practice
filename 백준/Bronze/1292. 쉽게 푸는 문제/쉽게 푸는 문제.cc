#include <iostream>
#define Max 1001
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //수열 생성
    int* Array = new int[Max];
    int N = 1; //배열의 Index
    //배열에 저장할 i
    for (int i = 1; N < 1001; i++){
        //i번 반복
        for (int j = 0; j < i; j++){
            Array[N++] = i;
            //배열 범위 넘어가는거 방지
            if (N >1000) {
                break;
            }
        }
    }
    int Start, End, Total = 0;
    cin >> Start >> End;
    //합 구하기
    for (int i = Start; i <= End; i++){
        Total += Array[i];
    }
    cout << Total << "\n";
    return 0;
}