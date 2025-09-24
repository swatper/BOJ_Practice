#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int length, width;
    cin >> width >> length;
    //2차원 배열 생성
    vector<string> maze(width);
    vector<vector<int>> visited(width, vector<int>(length, 0));
    //미로 입력
    for (int i = 0; i < width; i++){
        cin >> maze[i];
    }
    //탐색전 준비
    queue<pair<int, int>> nearList;
    visited[0][0] = 1;
    int nearX[4] = { -1, 0, 0, 1 }; //좌,하,상,우
    int nearY[4] = { 0, 1, -1, 0 };
    //탐색 시작 (너비 우선 탐색)
    nearList.push({0,0});
    while (!nearList.empty()) {
        //근처 탐색
        int curX = nearList.front().second;
        int curY = nearList.front().first;
        nearList.pop();

        for (int i = 0; i < 4; i++){
            int nextX = curX + nearX[i];
            int nextY = curY + nearY[i];
            //길이 있는지 확인
            if (nextX >= 0 && nextX < length && nextY >= 0 && nextY < width &&
                maze[nextY][nextX]== '1' && visited[nextY][nextX] == 0) {
                visited[nextY][nextX] = visited[curY][curX] + 1;
                nearList.push({nextY, nextX});
            }
        }
    }
    cout << visited[width - 1][length - 1] << "\n";
    return 0;
}
