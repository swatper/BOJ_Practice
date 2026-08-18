using System;

public class Solution {
    public int solution(int[] num_list) {
        int answer = 0;
        for(int i = 0; i < num_list.Length; i++){
            while(num_list[i] != 1){
                num_list[i] /= 2;
                answer++;
            }
        }
        return answer;
    }
}