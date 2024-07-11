#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int fruits, length;
	vector<int> fruitsDistance;
	cin >> fruits >> length;
	for (int  i = 0; i < fruits; i++){
		int distance;
		cin >> distance;
		fruitsDistance.push_back(distance);
	}
	//오름차순 정렬
	sort(fruitsDistance.begin(), fruitsDistance.end());

	for (int i = 0; i < fruits; i++){
		//과일의 거리가 길이가 같거나 작으면 과일을 먹을 수 있음
		//뱀의 길이 증가 시킴
		if (fruitsDistance[i] <= length){
			length++;
		}
		//거리가 더 멸면 다음 과일을 모두 먹을 수 없으므로 반복문 중단
		else if (fruitsDistance[i] > length){
			break;
		}
	}
	cout << length << "\n";
	return 0;
}