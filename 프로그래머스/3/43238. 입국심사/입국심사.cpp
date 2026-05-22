#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long right = 0;
    long long officers = times.size();
    //가장 일 처리가 늦는 사람 찾기 (최대 시간 계산)
    sort(times.begin(), times.end());
    right = (long long)times.back() * n;
        
    long long midTime;
    while(left <= right){
        long long totalPassengers = 0;
        midTime = (left + right) / 2;
        //특정 시간 기준으로 각 직원이 처리할 수 있는 여행객 계산
        for(int i = 0; i < officers; i++)
            totalPassengers += midTime/times[i];
        
        if(totalPassengers >= n){
            answer = midTime;
            right = midTime - 1;
        }
        else
            left = midTime + 1;
    }
    return answer;
}