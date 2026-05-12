#include <string>
#include <vector>
#include <unordered_map>
#define MAX 100001

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> gemList;
    int gemID = 0;
    //사야할 보석 목록 저장 (중복 제거)
    for (int i = 0; i < gems.size(); i++) {
        if (gemList.find(gems[i]) == gemList.end())
            gemList[gems[i]] = gemID++;
    }

    vector<int> answer = {1, MAX};

    //map은 중복이 없으므로, 크기를 비교해서 확인
    unordered_map<int, int> gemCart;
    int front = 0, back = 0;
    int gap = answer[1];

    while (true) {
        int targetID;
        //모든 종류의 보석을 하나씩 담았을(샀을) 경우
        if (gemList.size() == gemCart.size()) {
            //가장 작은 구간 찾기
            if (gap > back - front) {
                gap = back - front;
                answer[0] = front + 1;
                answer[1] = back;
            }
            targetID = gemList[gems[front]];
            gemCart[targetID]--;
            if (gemCart[targetID] == 0)
                gemCart.erase(targetID);
            front++;
        }
        else if (back >= gems.size()) 
            break;
        //아직 담아야할(사야할) 보석이 남을 경우
        else {
            targetID = gemList[gems[back]];
            gemCart[targetID]++;
            back++;
        }
    }
    return answer;
}