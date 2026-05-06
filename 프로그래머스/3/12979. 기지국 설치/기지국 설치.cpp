#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int stationIndex = 0;
    int nowApart = 0;
    
    while(nowApart < n){
        //기지국이 설치 된 곳의 전파 범위확인
        if(stationIndex < stations.size() && nowApart >= (stations[stationIndex] - 1) - w) {
            //범위 안이면, 그 기지국의 전파 범위 끝으로 이동
            nowApart = stations[stationIndex] + w;
            stationIndex++;
        }
        else{
            //새로 설치 한 곳의 뒤쪽 범위도 전파가 닿이므로, 띄우기
            nowApart += w * 2 + 1;
            //기지국 설치
            answer++;
        }
    }
    return answer;
}