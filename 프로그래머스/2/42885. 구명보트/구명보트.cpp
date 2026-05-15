#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    //오름차순 정렬
    sort(people.begin(), people.end());
    //최대 두명만 탈 수 있으니 투 포인터를 이용
    int light = 0, heavy = people.size() - 1;
    int totalWeight;
    while(light <= heavy){
        totalWeight = people[light] + people[heavy];
        //가장 가벼운 사람과 무거운 사람을 같이 태웠을 때, 제한 무게를 초과하면 무거운 사람만 태움
        if(totalWeight > limit)
            heavy--;
        else{
            heavy--;
            light++;
        }
        answer++;
        
    }
    return answer;
}