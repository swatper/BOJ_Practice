#include <string>
#include <vector>
#include <unordered_map> //2020카카오 인턴쉽 "보석 쇼핑" 문제에서 일반 map 사용시 시간 초과가 발생해서 unordered_map 사용
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int round = 0, target = 0;
    bool isPass = true;
    unordered_map<string, bool> usedWord;

    //끝말잇기 시작
    char endChar = words[0].back();
    usedWord[words[0]] = true;
    for (int i = 1; i < words.size(); i++) {
        target = (i % n) + 1;
        round = (i / n) + 1;
        //단어 끝 문자 및 이미 사용한 단어인지 확인(패배 확인)
        if (endChar != words[i][0] || usedWord.find(words[i]) != usedWord.end()) {
            isPass = false;
            break;
        }
        //사용한 단어 목록에 추가 및 끝 문자 설정
        usedWord[words[i]] = true;
        endChar = words[i].back();
    }

    //결과 확인
    answer.push_back(isPass ? 0 : target);
    answer.push_back(isPass ? 0 : round);
    return answer;
}