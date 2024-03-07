#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int* BookArray = new int [N];//책을 넣는 더미	
	while (true){
		int insert_Books;		//넣는 책의 수
		int check = 0;

		//책을 더미에 넣을 때 최근에 들어온 책의 번호가 이전에 들어온 책의 번호보다 크면
		//책의 번호 순서대로 나열할 수 없음을 판별하는 과정
		for (int i = 0; i < M; i++) { //0번째 더미부터 M-1번쪠 더미까지 반복
			cin >> insert_Books;
			for (int j = 0; j < insert_Books;j++) {//더미에 책을 입력
				cin >> BookArray[j];			   //더미에 책(번호)을 저장
				if (j == 0) {							//각 더미의 맨 아래(0번째)에 책을 저장
					continue;						//바로 반복문을 넘김
				}				
				if (BookArray[j - 1] < BookArray[j]) { // 최근에 들어온 책의 번호가 이전에 들어온 책의 번호보다 큰지 확인
					//cout << BookArray[j - 1] <<" " << BookArray[j] << endl;
					check++;
				}
			}
		}
		if (check > 0) {
			cout << "No\n";
			break;
		}
		else { //지금까지 넣은 책의 수와 전체 책의 수(N)이 같으면
			cout << "Yes\n";
			break;				//while문 종료
		}
	}
	delete[] BookArray;
	return 0;
}