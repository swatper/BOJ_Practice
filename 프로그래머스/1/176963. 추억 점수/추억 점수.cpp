#include <string>
#include <vector>
#include <unordered_map> //Hash map 기반

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> yearningList;

    for (int i = 0; i < name.size(); i++)
        yearningList.insert({ name[i], yearning[i] });

    for (int a = 0; a < photo.size(); a++) {
        int yearningScore = 0;
        for (int b = 0; b < photo[a].size(); b++) {
            if (yearningList.find(photo[a][b]) != yearningList.end()) {
                yearningScore += yearningList[photo[a][b]];
            }
        }
        answer.push_back(yearningScore);
    }
    return answer;
}