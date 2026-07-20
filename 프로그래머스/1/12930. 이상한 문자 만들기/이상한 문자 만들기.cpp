#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char tmpSpell;
    int spellIndex = 0;
    for (int alpha = 0; alpha < s.length(); alpha++) {
        tmpSpell = s[alpha];
        //공백 문자면 그 다음 문자는 첫 문자이므로 단어 인덱스 초기화
        if (tmpSpell == ' ') {
            spellIndex = 0;
        }
        else {
            //소문자 -> 대문자
            if (spellIndex % 2 == 0) {
                if (tmpSpell >= 'a' && tmpSpell <= 'z')
                    tmpSpell -= 32;
            }
            //대문자 -> 소문자
            else {
                if (tmpSpell >= 'A' && tmpSpell <= 'Z')
                    tmpSpell += 32;
            }
            spellIndex++;
        }
        //변환 완료된 문자 저장
        answer += tmpSpell;
    }
    return answer;
}