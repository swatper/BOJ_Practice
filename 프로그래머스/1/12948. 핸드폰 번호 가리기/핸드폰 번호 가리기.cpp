#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int phone_number_lenth = phone_number.length();
    for(int number = 0; number < phone_number_lenth; number++){
        answer += number < (phone_number_lenth - 4) ? '*' : phone_number[number];
    }
    return answer;
}