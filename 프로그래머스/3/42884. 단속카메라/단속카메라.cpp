#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//나가는 시간 기준으로 정렬
bool Compare(vector<int>& a, vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), Compare);
    
    int camPos = -30001;
    for(int route = 0; route < routes.size(); route++){
        //현재 도착 차량의 나가는 시간에 카메라 설치(해당 차량은 무조건 찍음)
        //근데 만약 그 카메라 위치(이전 차량의 나가는 시간)전에 현재 차량이 도착하면 찍을 수 있으므로 스킵
        if(camPos < routes[route][0]){
            answer++;
            camPos= routes[route][1];
        }
    }
    
    return answer;
}