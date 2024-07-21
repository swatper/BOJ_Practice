#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//매팽 연습 13
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<string, int> fileTypes;
	int files;
	cin >> files;
	for (int i = 0; i < files; i++){
		string fileName, fType;
		cin >> fileName;
		int index = fileName.length() - 1;
		while(fileName[index] != '.') {
			fType += fileName[index];
			index--;
		}
		//확장자 이름을 거꾸로 가져오므로 반전 시키기
		reverse(fType.begin(), fType.end());
		fileTypes[fType]++;
	}
	//반복자 사용
	for (auto iter = fileTypes.begin(); iter != fileTypes.end(); iter++){
		cout << iter->first << " " << iter->second << "\n";
	}
	return 0;
}