#include <string>
#include <vector>
using namespace std;

//계수 정렬 사용하기
long long solution(long long n) {
    long long answer = 0;
    //0 ~ 9까지 숫자가 등장한 횟수를 저장할 배열 준비 (인덱스 = 자릿수 숫자 -> 정렬된 표)
    vector<int> numList(10, 0);
    //각 데이터(정수)의 갯수 저장
    while(n > 0){
        numList[n % 10]++;
        n /= 10;
    }
    //정렬된 결과를 바탕으로 최종 결과값 구하기
        //내림차순 정렬이므로, 가장 큰 값에서부터 시작
    for(int data = 9; data >= 0; data--){
        //해당 숫자가 등장한 만큼 반복
        for(int cnt = 1; cnt <= numList[data]; cnt++){
            answer = answer * 10 + data;
        }
    }
    return answer;
}