#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Total = 0;
    for (int i = 0; i < 5; i++) {
        cin >> N;
        Total += N;
    }
    cout << Total << "\n";
    return 0;
}