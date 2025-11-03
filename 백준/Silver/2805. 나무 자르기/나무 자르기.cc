#include <iostream>
#include <algorithm>
using namespace std;

unsigned long  BinarySearch(int*List, int size, int target);
unsigned long Total(int* List, int size, unsigned long value);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int trees, req;
	cin >> trees >>req;
	int* treeList = new int[trees];
	for (int i = 0; i < trees; i++){
		cin >> treeList[i];
	}
	//크기 순서대로 오름차순  정렬
	sort(treeList, treeList + trees);
	cout << BinarySearch(treeList, trees, req)  << '\n';
	return 0;
}

unsigned long BinarySearch(int* List, int size, int target) {
	unsigned long front = 0;
	unsigned long back = List[size - 1];
	unsigned long sum, result = 0, height = 0;

	while (front  <= back) {
		height = (front + back) / 2;
		sum = Total(List, size, height);
		if (sum == target) {
			result = height;
			break;
		}
		if (sum > target) {
			result = height;
			front = height + 1;
		}
		else if(sum < target) {
			back = height - 1;
		}
	}
	return result;
}

unsigned long  Total(int* List, int size, unsigned long value) {
	unsigned long sum = 0;
	for (int i = 0; i < size; i++){
		if (List[i] > value) {
			sum += List[i] - value;
		}
	}
	return sum;
}