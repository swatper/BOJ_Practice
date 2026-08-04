public class Solution {
    public string solution(string s) {
        string answer = "";
        if(s.Length % 2 != 0){
            answer += s[s.Length / 2];
        }
        else{
            int mid = s.Length / 2;
            answer += s[mid - 1];
            answer += s[mid];
        }
        return answer;
    }
}