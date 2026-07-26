#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a){
        //b개씩 가져다주고 돌려 받은 병 수
        int restBottles = (n / a) * b;
        answer += restBottles;
        //최종적으로 남은 병 수 계산 (돌려 받은 병 수 + 기존에 남은 병 수)
        n = (n % a) + restBottles;
    }
    return answer;
}