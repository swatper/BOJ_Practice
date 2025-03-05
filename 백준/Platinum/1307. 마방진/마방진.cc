/*"생활속의수리"때 배운 마방진 내용 구현*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void ODD(vector<vector<int>> &targets, int size);
void Case4N(vector<vector<int>>& target, int size);
void Case4N2(vector<vector<int>>& target, int size);
void Swap(int *a, int *b);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int size;
	cin >> size;
	//마장진 2차원 배열 생성
	vector<vector<int>> Mabang(size, vector<int>(size));

	//홀수 차수 마방진일 대
	if (size %2 != 0){
		ODD(Mabang, size);
	}
	else {
		//4n차 마방진이일 때
		if (size % 4 == 0) {
			Case4N(Mabang,size);
		}
		else if (size % 4 == 2) {
			Case4N2(Mabang, size);
		}
	}
	//결과 확인
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << Mabang[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//샴(Siam)방법 사용
void ODD(vector<vector<int>> &target, int size) {
	int curRow = 0, curCol = size / 2;
	for (int i = 1; i <= size * size; i++){
		target[curRow][curCol] = i;
		//오른쪽 위 대각선으로 이동
		int nextRow = (curRow - 1 + size) % size;
		int nextCol = (curCol + 1) % size;

		//다음 위치에 이미 숫자가 있다면 아래로 이동
		if (target[nextRow][nextCol] != 0) {
			curRow = (curRow + 1) % size;
		}
		else {
			curRow = nextRow;
			curCol = nextCol;
		}
	}
}

//1:2:1 공식 사용
void Case4N(vector<vector<int>>& target, int size) {
    //1: 1부터 채우기
	int num = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            target[i][j] = num++;
        }
    }

	//2: 값 바꾸기
	for (int i= 0; i < size/4; i++) {
		int col1 = size / 4;
		int col2 = size - size / 4 - 1;
		for (int k = 0; k < size / 2; k++) {
			Swap(&target[i][col1] , &target[size - 1 - i][col2]);
			Swap(&target[col1][i], &target[col2][size - 1 - i]);
			col1++;
			col2--;
		}
	}
}

void Case4N2(vector<vector<int>>& target, int size) {
	//(2n + 1)차 마방진 구하기
	int subSize = size / 2; 
	vector<vector<int>> subBang(subSize, vector<int>(subSize));
	ODD(subBang, subSize);
	//나머지 구역 채워넣기
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j < size/2; j++) {
			//A구역 삽입
			target[i][j] = subBang[i][j];
			//B구역 삽입
			target[i + subSize][j + subSize] = target[i][j] + (subSize * subSize);
			//C구역 삽입
			target[i][j + subSize] = target[i + subSize][j + subSize]  + (subSize * subSize);
			//D 구역 삽입
			target[i + subSize][j] = target[i][j + subSize] + (subSize * subSize);
		}
	}
	int k = (size - 2) / 4;
	//A영역 D영역 자리 바꾸기
	for (int i = 0; i < subSize; i++){
		for (int j = 0; j < k; j++){
			Swap(&target[i][j], &target[i + subSize][j]);
		}
	}
	//B영역과 C영역 바꾸기
	for (int i = 0; i < subSize; i++) {
		for (int j = (size - k + 1); j < size; j++) {
			Swap(&target[i][j], &target[i + subSize][j]);
		}
	}
	//A영역의 중앙값과 D영역의 중앙값 바꾸기
	Swap(&target[subSize/2][subSize/2],&target[subSize/2 + subSize][subSize/ 2]);
	//A영역 중간 줄의 첫 번째 값과 D영역 중간 줄의 첫 번째 값 바꾸기
	Swap(&target[subSize/2][0],&target[subSize / 2 + subSize][0]);
}

//4n차/4n+2마방진 참고
//https://destiny738.tistory.com/247
//https://en.wikipedia.org/wiki/Strachey_method_for_magic_squares