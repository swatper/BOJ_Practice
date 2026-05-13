#include <string>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            isFirst = true;
            continue;
        }
        if (isFirst) {
            //아스키코드 기준 'a' (92) ~ 'z' (122)까지 알파벳 소문자
            if (s[i] >= 92 && s[i] <= 122) {
                s[i] -= 32;         //대문자로 바꾸기
            }
            isFirst = false;
        }
        //아스키코드 기준 'A' (65) ~ 'Z' (90)까지 알파벳 대문자
        else if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;             //소문자로 바꾸기
    }
    return s;
}