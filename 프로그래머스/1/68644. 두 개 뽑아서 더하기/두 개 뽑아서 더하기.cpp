#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> ableNumbers;
    //오름차순 정렬
    sort(numbers.begin(), numbers.end());
    for (int a = 0; a < numbers.size() - 1; a++) {
        for (int b = a + 1; b < numbers.size(); b++) {
            ableNumbers.push_back(numbers[a] + numbers[b]);
        }
    }
    //정렬
    sort(ableNumbers.begin(), ableNumbers.end());
    int result = 0; //중복 확인용 index
    for (int able = 0; able < ableNumbers.size(); able++) {
        //중복 확인
        if (answer[result - 1] != ableNumbers[able] || able == 0) {
            answer.push_back(ableNumbers[able]);
            result++;
        }
    }
    return answer;
}