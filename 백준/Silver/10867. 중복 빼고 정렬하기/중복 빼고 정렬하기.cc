#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> numbers;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int number;
		cin >> number;
		numbers.push_back(number);
	}
	//오름 차순으로 정렬
	sort(numbers.begin(), numbers.end());
	//uniqu()를 통해 중복된 원소를 맨 뒤로 보냄
	//erase()를 통해 원소 삭제
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << " ";
	}
	cout << "\n";
	return 0;
}
//참고:https://sangwoo0727.github.io/c++/Cplus-unique/