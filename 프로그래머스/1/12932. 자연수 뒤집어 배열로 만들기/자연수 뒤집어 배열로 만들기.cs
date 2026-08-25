using System.Collections.Generic;

public class Solution {
    public int[] solution(long n) {
        //List 동적 배열 사용
        List<int> answer = new List<int>();
        while(n > 0){
            answer.Add((int)(n % 10));
            n/= 10;
        }
        //List에서 배열(Array)로 변환
        return answer.ToArray();
    }
}