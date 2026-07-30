#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n << " is " << (((n % 2 == 0)) ? "even" : "odd");
    return 0;
}