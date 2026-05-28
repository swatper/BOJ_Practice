#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//대학생 멀티미디어 수업에서 무손실 압축 기법으로 배웠음
vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> LZWDictionary;

    //사전 준비
    int charIndex = 1;
    string alphabet = "A";
    for (int i = 0; i < 26; i++) {
        LZWDictionary[alphabet] = charIndex++;
        alphabet[0]++;
    }

    //압축 시작
    string tmp = "";
    for (int i = 0; i < msg.size(); i++) {
        char curChar = msg[i];
        string word = tmp + curChar;
        //문자가 있는지 확인
        if (LZWDictionary.find(word) != LZWDictionary.end()) {
            //이미 있는 문자면 문자열 확장
            tmp = word;
        }
        else {
            //없을 경우 사전에 추가
            answer.push_back(LZWDictionary[tmp]);
            LZWDictionary[word] = charIndex++;
            tmp = curChar;
        }
    }

    //맨 마지막 문자 처리
    if (!tmp.empty())
        answer.push_back(LZWDictionary[tmp]);


        return answer;
}