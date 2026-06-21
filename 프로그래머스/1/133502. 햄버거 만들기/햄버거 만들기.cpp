#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    //1: 빵 2: 야채, 3: 고기
    int hamburgers = 0;
    vector<int> preparedIingredient;   //만들고 있는 햄버거
    for (int ingredientIndex = 0; ingredientIndex < ingredient.size(); ingredientIndex++) {
        preparedIingredient.push_back(ingredient[ingredientIndex]);
        //준비된 재료 수 확인
        int prepared = preparedIingredient.size();
        if (prepared >= 4) {
            //햄버거 만들 수 있는 지 확인
            if (preparedIingredient[prepared - 4] == 1 &&
                preparedIingredient[prepared - 3] == 2 &&
                preparedIingredient[prepared - 2] == 3 &&
                preparedIingredient[prepared - 1] == 1) {
                //사용한 재료 빼기
                for (int i = 0; i < 4; i++)
                    preparedIingredient.pop_back();
                hamburgers++;
            }
        }
    }
    return hamburgers;
}