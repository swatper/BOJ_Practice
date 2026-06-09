#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//문자열을 숫자로 변환
long long StringToNum(string& target) {
    long long result = 0;
    for (int i = 0; i < target.size(); i++) 
        result = result * 26 +  (target[i] - 'a' + 1);
     return result;
};

//숫자를 문자열로 변환
string NumToString(long long& target) {
    string result = "";
    while (target > 0) {
        target -= 1;
        result = (char)('a' + (target % 26)) + result;
        target /= 26;
    }
    return result;
}

//문자열의 각 자리마다 확인하는 것 보다는 문자열을 숫자로 바꿔서 계산하는 것이 빠름
string solution(long long n, vector<string> bans) {
    string answer = "";
    //금지하려는 주문을 숫자로 바꾼 후 정렬해서 저장
    vector<long long> bansNumber;
    for (int ban = 0; ban < bans.size(); ban++)
        bansNumber.push_back(StringToNum(bans[ban]));

    sort(bansNumber.begin(), bansNumber.end());

    for (int ban = 0; ban < bansNumber.size(); ban++) {
        //순서가 뒤거나, 금지된 주문이면 n번째 순서를 뒤로 밀기
        if (bansNumber[ban] <= n)
            n++;
        else
            break;
    }

    answer = NumToString(n);
    return answer;
}