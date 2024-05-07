#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int BF, GF;
    while (true) {
        cin >> BF >> GF;
        if (GF == 0 && BF == 0) {
            break;
        }
        cout << GF + BF << "\n";
    }
    return 0;
}