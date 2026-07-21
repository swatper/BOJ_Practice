#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0;
    int tmp;
    for(int number = 0; number < absolutes_len; number++){
        //양수 음수 판별
        tmp = signs[number] ? absolutes[number] : -absolutes[number];
        answer+= tmp;
    }
    return answer;
}