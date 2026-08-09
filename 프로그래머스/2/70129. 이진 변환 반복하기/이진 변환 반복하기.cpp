#include <string>
#include <vector>
using namespace std;

//10진수 -> 2진수 변환
string NumberToBinary(int target) {
    string tmp = "";
    while (target > 0) {
        //나머지 확인
            //역순으로 계산하므로 역순으로 저장
        tmp = (target % 2 == 1 ? "1" : "0") + tmp;
        target /= 2;
   }
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zeroCnt = 0;    //지워야할 총 문자열 수
    int tryCnt = 0;       //시도 횟수

    //입력 받은 문자열이 "1"이 될 때까지 반복
    while (s != "1") {
        tryCnt++;
        int tmpSize = 0;

        //지워야할 0 갯수 확인 및 제거 후 길이 측정
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                tmpSize++;
            }
            else 
                zeroCnt++;
        }
        //문자열 길이 값을 이진수로 변환
        s = NumberToBinary(tmpSize);
    }

    //결과 저장
    answer.push_back(tryCnt);
    answer.push_back(zeroCnt);
    return answer;
}