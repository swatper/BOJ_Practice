#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long numerP = 0;
    long long numberSub = 0;
    
    //자릿수 확인
    long long digit = 1;
    //슬라이딩 윈도우 크기
    int window = p.length();
    
    //문자열 P를 숫자 P로 바꾸기
    for(int i = 0; i < window; i++){
        numerP = numerP * 10 + (p[i] - '0');
        numberSub = numberSub * 10 + (t[i] - '0');
        if(i > 0)
            digit *= 10;
    }
    //첫 번째 부분 문자열 비교
    if(numberSub <= numerP){
        answer++;
    }    
    
    //이후 부분문자열 찾기 (슬라이딩 윈도우)
    for(int sub = window; sub < t.length(); sub++){
        //맨 앞 자리 제거
        numberSub %= digit;
        //뒷 자리 추가
        numberSub =  numberSub * 10 + (t[sub] - '0');        
        //숫자 크기 비교
        if(numberSub <= numerP)
            answer++;
    }
    return answer;
}