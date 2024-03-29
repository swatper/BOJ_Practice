#include <iostream>
using namespace std;

string WhiteChess[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string BlackChess[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, White = 0,Black = 0, Min = 32;
	cin >> N >> M;
	string *GivenChess = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> GivenChess[i];
	}
	//입력 받은 전체 체스판의 행
	for (int i = 0; i <= N - 8; i++) {
		//입력 받은 전체 체스판의 열부터 실행
		for (int j = 0; j <= M - 8; j++) {
			int Try = 0;
			//8X8로 뽑아낸 체스판과 완성된(?) 체스판과 비교해서 바꿔야할 칸 구하기
			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (GivenChess[i + a][j + b] != WhiteChess[a][b]) {
						White++;
					}
					if (GivenChess[i + a][j + b] != BlackChess[a][b]) {
						Black++;
					}
				}
			}
			Try = White < Black ? White : Black;
			Min = Try < Min ? Try : Min;
			White = 0;
			Black = 0;
		}
	}
	cout << Min << "\n";
	return 0;
}