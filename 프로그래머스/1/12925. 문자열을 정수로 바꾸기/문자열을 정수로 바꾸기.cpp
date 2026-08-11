#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    //자연수(양수) 플레그
    bool isNature = true;
    int start = 0;
    
    //부호 상태 유무 확인
    if(s[0] == '-'){
        isNature = false;
        start = 1;
    }
    else if (s[0] == '+'){
        start = 1;
    }
    
    for(int i = start; i < s.size(); i++){    
        //0의 아스키 코드는 48
        answer = answer * 10 + (s[i] - '0');
    }
    answer = isNature ? answer : -answer;
    return answer;
}