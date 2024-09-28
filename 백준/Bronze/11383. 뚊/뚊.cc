#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	bool IsEyfa = true;
	cin >> N >> M;
	//배열 동적 할당
	string* Images = new string[N * 2];

	for (int i = 0; i < N * 2; i++){
		cin >> Images[i];
	}

	for (int i = 0; i < N; i++){
		//2배 길어진 문자열 비교에서 사용할 인덱스
		int index = 0;
		for (int j = 0; j < M; j++){
			//문자 비교
			if (Images[i][j] == Images[i + N][j + index] && Images[i][j] == Images[i + N][j + 1 + index]){
				index++;
			}
			else {
				IsEyfa = false;
				break;
			}
		}
		if (!IsEyfa){
			break;
		}
	}

	if (IsEyfa){
		cout << "Eyfa\n";
	}
	else {
		cout << "Not Eyfa\n";
	}

	return 0;
}