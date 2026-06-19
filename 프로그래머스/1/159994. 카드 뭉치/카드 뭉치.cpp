#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int card1Index = 0;
    int card2Index = 0;
    bool isPossible = true;
    for (int g = 0; g < goal.size(); g++) {
        if (card1Index < cards1.size() && cards1[card1Index] == goal[g]) 
            card1Index++;
        else if (card2Index < cards2.size() && cards2[card2Index] == goal[g])
            card2Index++;
        else {
            isPossible = false;
            break;
        }
    }
    answer = isPossible ? "Yes" : "No";
    return answer;
}
