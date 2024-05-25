#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int Pieces[6] = { 1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; i++)
    {
        //현제 갖고있는 말 갯수 입력받기
        int HavingPieces;
        cin >> HavingPieces;
        //각 말의 필요한 개수 계산
        Pieces[i] -= HavingPieces;
    }
    for (int i = 0; i < 6; i++)
    {
        cout << Pieces[i] << " ";
    }
    cout << "\n";

    return 0;
}