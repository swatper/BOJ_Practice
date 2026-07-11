#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subArray;
    for (int command = 0; command < commands.size(); command++) {
        //부분 베열 만들기
        for (int part = commands[command][0] - 1; part < commands[command][1]; part++)
            subArray.push_back(array[part]);
        //정렬
        sort(subArray.begin(), subArray.end());
        //결과 저장
        answer.push_back(subArray[commands[command][2] - 1]);
        subArray.clear();
    }
    return answer;
}