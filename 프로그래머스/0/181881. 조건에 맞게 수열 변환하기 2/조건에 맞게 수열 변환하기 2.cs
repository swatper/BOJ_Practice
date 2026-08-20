using System;
using System.Linq;

public class Solution {
    public void DoWork(int[] target){
        for(int i = 0; i < target.Length; i++){
            //50보다 크거나 같은 "짝수"
            if(target[i] >= 50 && target[i] % 2 == 0)
                target[i] /= 2;
            //50보다 작은 "홀수"
            else if(target[i] < 50 && target[i] % 2 != 0)
                target[i] = target[i] * 2 + 1;
        }
    }
    
    public bool CompareArray(int[] arrA, int[] arrB){
        bool isSame = true;
        for(int i = 0; i < arrA.Length; i++){
            if(arrA[i] != arrB[i]){
                isSame = false;
                break;
            }
        }
        return isSame;
    }
    
    public int solution(int[] arr) {
        int answer = 0;
        while(true){
            //배열 복사
            int[] tmp = arr.ToArray();
            DoWork(tmp);
            //이전 배열과 새로 작업한 배열이 서로 같은(?)지 확인
            if(CompareArray(arr, tmp))
                break;
            //다르면 새로운 결과를 저장 
            arr = tmp.ToArray(); 
            answer++;
        }
        return answer;
    }
}