#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int mod = 1000000007;
    //연못 설치
    for(int p = 0; p < puddles.size(); p++)
        matrix[puddles[p][1] - 1][puddles[p][0] - 1] = -1;
    
    //시작점 설정
    matrix[0][0] = 1;
    
    //가로 첫 줄 초기화 (항상 최단 경로는 1)
    for(int x = 1; x < m; x++){
        if(matrix[0][x] == -1)
            continue;
        if(matrix[0][x - 1] == 1)
            matrix[0][x] = 1;
    }
    
    //세로 첫 줄 초기화 (항상 최단 경로는 1)
    for(int y = 1; y < n; y++){
        if(matrix[y][0] == -1)
            continue;
        if(matrix[y - 1][0] == 1)
            matrix[y][0] = 1;
    }
    
    for(int y = 1; y < n; y++){
        for(int x = 1; x < m; x++){
            if(matrix[y][x] == -1)
                continue;
            //연못이 근처에 있으면 그 방향으로 올 수 없음
            int left = matrix[y][x - 1] == -1 ? 0 : matrix[y][x - 1];
            int up = matrix[y - 1][x] == -1 ? 0 : matrix[y - 1][x];
            matrix[y][x] = (left + up) % mod;
        }
    }
    return matrix[n - 1][m - 1];
}