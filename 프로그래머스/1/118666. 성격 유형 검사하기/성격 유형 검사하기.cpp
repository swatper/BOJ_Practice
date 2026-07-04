#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer;
    //각 유형(8가지)의 총점을 계산 저장
    map<char, int> character;
    //각 설문지에 대한 유형 총점 계산
    for (int choice = 0; choice < choices.size(); choice++) {
        switch (choices[choice]) {
        case 0: 
            break;
        case 1:
            character[survey[choice][0]] += 3;
            break;
        case 2:
            character[survey[choice][0]] += 2;
            break;
        case 3:
            character[survey[choice][0]] += 1;
            break;
        case 5:
            character[survey[choice][1]] += 1;
            break;
        case 6:
            character[survey[choice][1]] += 2;
            break;
        case 7:
            character[survey[choice][1]] += 3;
            break;
        }
    }
    //성격 결과는 결국 4자리
    answer.push_back(character['R'] >= character['T'] ? 'R' : 'T');
    answer.push_back(character['C'] >= character['F'] ? 'C' : 'F');
    answer.push_back(character['J'] >= character['M'] ? 'J' : 'M');
    answer.push_back(character['A'] >= character['N'] ? 'A' : 'N');
    return answer;
}