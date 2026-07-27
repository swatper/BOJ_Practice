#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    //제일 작은 값과 인덱스 구하기
    int minIndex = 0;
    int curMin = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (curMin > arr[i]) {
            curMin = arr[i];
            minIndex = i;
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        if (i != minIndex)
            answer.push_back(arr[i]);
    }
    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}