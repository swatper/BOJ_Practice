#include <iostream>

using namespace std;

int main() {

    cin.tie(NULL);

    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    for (int i = 1; i <= 9; i++){

        cout << N << " * " << i << " = "<< i * N << "\n"; 

    }

    return 0;

}