#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //공의 위치를 알려주는 bool형태의 배열
    //공이 있는 컵의 bool값은 true
    bool Cups[4] = {false, true, false, false};
    int Tc;
    cin >> Tc;
    for (int i = 0; i < Tc; i++){
        int CupA, CupB;
        cin >> CupA >> CupB;
        //컵 위치 바꾸기
        bool tmp = Cups[CupB];
        Cups[CupB] = Cups[CupA];
        Cups[CupA] = tmp;
    }
    for (int i = 1; i < 4; i++){
        //공이 들어있는 컵 찾기
        if (Cups[i]){
            cout << i << "\n";
            //찾으면 반복문 종료(공은 하나이므로 더이상 찾을 필요 없음)
            break;
        }
    }
    return 0;
}