#include <iostream>
#include <string>
using namespace std;

string Rev(string Num);

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    string NumA, NumB, Result;
    int total;
    cin >> NumA >> NumB;
    NumA = Rev(NumA);
    NumB = Rev(NumB);
    //stoi()를 이용해서 문자열을 정수로 변하여 합 계산
    total = stoi(NumA) + stoi(NumB);
    //합 계산 후 문자 뒤집기
    Result = Rev(to_string(total));
    //앞자리가 0이 오는것을 방지하기 위해 다시 정수로 변환
    cout << stoi(Result) << "\n";
    return 0;
}

//문자 뒤집는 함수
string Rev(string Num) {
    string Temp = "";
    for(int i = Num.length() - 1; i >= 0; i--){
        //맨 뒤에 있는 문자 순서대로 저장
        Temp += Num[i];
    }
    return Temp;
}