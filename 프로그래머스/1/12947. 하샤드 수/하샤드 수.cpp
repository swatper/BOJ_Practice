#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, tmp = x;
    //각 자리 수 합 구하기
    while(tmp > 0){
        sum += tmp % 10;
        tmp /= 10;
    }
    return x % sum == 0;
}