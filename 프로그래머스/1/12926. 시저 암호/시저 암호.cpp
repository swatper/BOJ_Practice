#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    char tmp;
    //암호화
    for(int spell = 0; spell < s.length(); spell++){
        tmp = s[spell];
        if(s[spell] != ' '){
            //소문자 확인
            if(tmp >= 'a' && tmp <= 'z')
                tmp = 'a' + (tmp - 'a' + n) % 26;
            //대문자 확인
            if(tmp >= 'A' && tmp <= 'Z')
                tmp = 'A' + (tmp - 'A' + n) % 26;
        }
        answer += tmp;
    }
    return answer;
}