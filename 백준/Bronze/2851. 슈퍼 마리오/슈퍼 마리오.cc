#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int Total = 0;
    //버섯 점수 입력 받아서 저장
    int* MushroomList = new int[10];
    for (int i = 0; i < 10; i++) {
        cin >> MushroomList[i];
    }
    //누적 합 구해서 100에 가까운 수 찾기
    for (int i = 0; i < 10; i++) {
        //100에 가까운지 비교
        if (abs(100 - Total) < abs(100 - (Total + MushroomList[i]))) {
            break;
        }
        else {
            //누적 합
            Total += MushroomList[i];
        }
    }
    cout << Total << "\n";
    return 0;
}