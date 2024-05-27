#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int List[3] = {};
    for (int i = 0; i < 3; i++){
        cin >> List[i];
    }
    //정렬 알고리즘을 통해 오름 차순으로 정렬
    sort(List, List + 3);
    cout << List[1] << "\n";
    return 0;
}