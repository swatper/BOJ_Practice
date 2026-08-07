#include <string>
#include <vector>

using namespace std;

//누적합(백준)
long long solution(int n) {
    long long answer = 0;
    vector<unsigned long long> pos(n + 1, 0);
    pos[0] = 0;
    pos[1] = 1;
    pos[2] = 2;
    for(int curPos = 3; curPos < n + 1; curPos++){
        pos[curPos] += (pos[curPos - 1] + pos[curPos - 2]) % 1234567; 
    }
    return pos[n];
}