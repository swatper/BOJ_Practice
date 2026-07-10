#include <string>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    int answer = a + b + c;
    if(a == b && b == c && c == a)
        return answer * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    else if(a == b || b == c || c == a)
        return answer * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    else
        return answer;
}