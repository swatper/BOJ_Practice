#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int totalOdd = 0, totalEven = 0;
    for(int num = 0; num < num_list.size(); num++){
        totalOdd += num % 2 != 0 ? num_list[num] : 0;
        totalEven += num % 2 == 0 ? num_list[num] : 0;
    }
    answer = totalOdd > totalEven ? totalOdd : totalEven;
    return answer;
}