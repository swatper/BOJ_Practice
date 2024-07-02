#include <iostream>
#include <map>
using namespace std;

//매핑 연습 9
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, bool> emoticonList;
	int chatLogs, numOfEmoticons = 0;
	cin >> chatLogs;
	for (int i = 0; i < chatLogs; i++){
		string log;
		cin >> log;
		//ENTER가 입력되면
		if (log == "ENTER"){
			//이모티콘리스트(맵) 목록 삭제
			emoticonList.clear();
			continue;
		}
		//이모티콘을 사용한 적이 있으면(목록에 있으면) 넘어감
		if (emoticonList.find(log) != emoticonList.end()){
			continue;
		}
		else {
			emoticonList.insert({log, true});
			numOfEmoticons++;
		}
	}
	cout << numOfEmoticons << "\n";
	return 0;
}    