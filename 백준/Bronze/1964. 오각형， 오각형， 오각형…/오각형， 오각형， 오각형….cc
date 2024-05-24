#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long Step, TotalSpots = 0;;
    cin >> Step;
    //단계가 늘어날 때 마다 바깥쪽의 점의 갯수가 7(기본 4개 + 3개 증가)개씩 증가함
    TotalSpots = 1 + 4 * Step + 3 * Step * (Step - 1) / 2;

    //결과 값을 45678로 나눈 나머지를 구하라 함
    TotalSpots %= 45678;
    
    cout << TotalSpots << "\n";
    return 0;
}