#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool isPossible;
    int skillSequence;

    for (int a = 0; a < skill_trees.size(); a++) {
        isPossible = true;
        skillSequence = 0;

        //스킬 순서와 스킬 트리 확인
        for (int b = 0; b < skill_trees[a].size(); b++) {
            if (skill[skillSequence] == skill_trees[a][b]) {
                skillSequence++;
                //스킬 순서에 있는 스킬들을 모두 확인 했을 경우
                //스킬 트리의 이후 스킬들은 확인 할 필요 없음
                if (skillSequence >= skill.size()) {
                    isPossible = true;
                    break;
                }
            }
            //스킬 순서와 다른 스킬일 경우
            else {
                //스킬이 스킬 순서에 있는지 확인
                int targetSkill = -1;
                for (int c = 0; c < skill.size(); c++) {
                    if (skill[c] == skill_trees[a][b])
                        targetSkill = c;
                }
                //찾은 스킬의 순서가 현재 배워야할 스킬 순서보다 뒤면 불가능
                if (targetSkill != -1 && targetSkill > skillSequence){
                    isPossible = false;
                    break;
                }
            }

        }

        if (isPossible)
            answer++;
    }
    return answer;
}