#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(int a, int b);

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int Tc;
    cin >> Tc;
    for (int i = 0; i < Tc; i++){
        int boxes, candies, reqBoxes = 0;
        cin >> candies >> boxes;
        //박스 크기를 저장할 배열
        int* boxList = new int[boxes];

        for (int j = 0; j < boxes; j++){
            int width, length;
            cin >> width >> length;
            boxList[j] = width * length;
        }

        //내림차순 정렬
        sort(boxList, boxList + boxes, Compare);
        for (int j = 0; j < boxes; j++){
            //박스 사용
            candies -= boxList[j];
            reqBoxes = j;
            if (candies <= 0) {
                break;
            }
        }
        cout << reqBoxes + 1 << "\n";
        delete[] boxList;
    }
    return 0;
}

bool Compare(int a, int b) {
    return a> b;
}