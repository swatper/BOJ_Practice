#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, int> BookInfo;
	int Books, Max = 1;;
	cin >> Books;
	for (int i = 0; i < Books; i++){
		string Title;
		cin >> Title;
		//map에 key값이 Title인 책이 있으면
		BookInfo[Title]++; //그 Title에 대한 value값 증가
		//없으면 새로 추가함, map이 Key(Title)기준으로 자동정렬 함
		
		//가장 많이 팔린 책의 value값 저장
		Max = Max > BookInfo[Title] ? Max : BookInfo[Title];
	}
	//Iterator를 사용해서 탐색
	for (auto Iter: BookInfo) {
		if (Iter.second == Max){
			//사전순으로 가장 앞서는 제목 출력
			cout << Iter.first;
			break;
		}
	}
	cout << "\n";
	return 0;
}    
