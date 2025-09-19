#include <iostream>
#include <vector>

using namespace std;

void Up(int& posY, int& posX, const int& size,  vector<vector<bool>>& v_path);
void Down(int& posY, int& posX, const int& size, vector<vector<bool>>& v_path);
void Left(int& posY, int& posX, const int& size, vector<vector<bool>>& h_path);
void Right(int& posY, int& posX, const int& size, vector<vector<bool>>& h_path);

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int size, curX = 0, curY = 0;
    string command;
    cin >> size;
    //수평과 수직 흔적을 각각 기록할 2차원 bool 배열
    vector<vector<bool>> horizontalPath(size, vector<bool>(size, false));
    vector<vector<bool>> verticalPath(size, vector<bool>(size, false));

    cin >> command;

    for (int i = 0; i < command.length(); i++) {
        switch (command[i]) {
        case 'U':
            Up(curY, curX, size, verticalPath);
            break;
        case 'D':
            Down(curY, curX, size, verticalPath);
            break;
        case 'L':
            Left(curY, curX, size, horizontalPath);
            break;
        case 'R':
            Right(curY, curX, size, horizontalPath);
            break;
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            bool wentH = horizontalPath[i][j];
            bool wentV = verticalPath[i][j];
            if (wentH && wentV)
                cout << '+';
            else if (wentH)
                cout << '-';
            else if (wentV)
                cout << '|';
            else 
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}

void Up(int& posY, int& posX, const int& size, vector<vector<bool>>& v_path) {
    if (posY - 1 >= 0) {
        v_path[posY][posX] = true;
        posY--;
        v_path[posY][posX] = true;
    }
}

void Down(int& posY, int& posX, const int& size, vector<vector<bool>>& v_path) {
    if (posY + 1 < size) {
        v_path[posY][posX] = true;
        posY++;
        v_path[posY][posX] = true;
    }
}

void Left(int& posY, int& posX, const int& size, vector<vector<bool>>& h_path) {
    if (posX - 1 >= 0) {
        h_path[posY][posX] = true;
        posX--;
        h_path[posY][posX] = true;
    }
}

void Right(int& posY, int& posX, const int& size, vector<vector<bool>>& h_path) {
    if (posX + 1 < size) {
        h_path[posY][posX] = true;
        posX++;
        h_path[posY][posX] = true;
    }
}