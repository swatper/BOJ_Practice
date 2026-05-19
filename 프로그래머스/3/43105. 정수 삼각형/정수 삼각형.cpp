#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int tmp, answer = 0;
    int height = triangle.size();
    int dp[501][501] = {0, };
    dp[0][0] = triangle[0][0];
    
    //윗층 기준으로 아래쪽 계산 (탑 다운)
    for (int a = 0; a < height - 1; a++) {
        for (int b = 0; b < triangle[a].size(); b++) {
            //왼쪽 경로(자식)
            tmp = triangle[a + 1][b] + dp[a][b];
            dp[a + 1][b] = dp[a + 1][b] < tmp ? tmp : dp[a + 1][b];
            
            //오른쪽 경로(자식)
            tmp = triangle[a + 1][b + 1] + dp[a][b];
            dp[a + 1][b + 1] = dp[a + 1][b + 1] < tmp ? tmp : dp[a + 1][b + 1];
        }
    }
    
    int lastFloor = height - 1;
    //맨 아랫층 중에서 제일 큰 값 찾기
    for (int i = 0; i < triangle[lastFloor].size(); i++)
        answer = answer < dp[lastFloor][i] ? dp[lastFloor][i] : answer;

    return answer;
}