#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp = i * x;
        answer.push_back(tmp);
    }
    return answer;
}