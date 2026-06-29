#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string usableChar;
    //skip에 있는 문자를 제외한 나머지 문자 추출 (치환표 작성)
    for (char alpha = 'a'; alpha <= 'z'; alpha++) {
        if (skip.find(alpha) == string::npos)
            usableChar.push_back(alpha);
    }
    //암호문 해독하기
    for (int cryptogram = 0; cryptogram < s.length(); cryptogram++) {
        //치환표 보고 문자 위치 확인
        int encryptionIndex = usableChar.find(s[cryptogram]);
        //문자 위치 확인 후 복호화
        int decodingIndex = (encryptionIndex + index) % usableChar.length();
        //복호화 시킨 문자 저장
        answer.push_back(usableChar[decodingIndex]);
    }
    return answer;
}