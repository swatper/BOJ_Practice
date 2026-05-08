int solution(int n) {
    int answer = 0;
    
    //투 포인터로 접근
       //정렬(?)된 수를 순서대로 더해서 계산
    int start = 1, end = 1;
    int sum = 1;
    while(start <= n){
        if(sum == n){
            answer++;
            sum -= start;
            start++;
        }
        else if (sum < n){
            end++;
            sum += end;
        }
        else{
            sum -= start;
            start++;
        } 
    }
    return answer;
}