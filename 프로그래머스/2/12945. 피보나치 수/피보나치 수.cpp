#include <iostream>
#define MAX 1234567
#define SIZE 100000

using namespace std;

int solution(int n) {
    int *fibo = new int[SIZE];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= SIZE; i++){
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MAX;
    }
    
    return fibo[n];
}