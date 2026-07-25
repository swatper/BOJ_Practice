#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    //오름차순 정렬
    sort(d.begin(), d.end());
    for (int depart = 0; depart < d.size(); depart++) {
        if (budget >= d[depart]) {
            budget -= d[depart];
            answer++;
        }
        else
            break;
    }
    return answer;
}