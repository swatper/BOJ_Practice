#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    //등차수열 합 공식 이용: (첫 항 + 끝 항) * (항의 수) / 2
    answer = (long long) (a + b) * ((a > b ? (a - b): (b - a)) + 1 ) / 2;
    return answer;
}