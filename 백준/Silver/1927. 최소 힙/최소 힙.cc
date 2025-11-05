#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PopHeap(vector<int>& heap);
void InsertHeap(int target, vector<int> &heap);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int commands, command;
	//0번째가 루트
	vector<int> heap;
	cin >> commands;
	for (int i = 0; i < commands; i++){
		cin >> command;
		if (command == 0) {
			if (heap.empty()) 
				cout << 0 << '\n';
			else
				PopHeap(heap);
		}
		else {
			InsertHeap(command, heap);
		}
	}
	return 0;
}

void PopHeap(vector<int>& heap) {
	cout << heap[0] << '\n';
	//맨 뒤로 보내고(vector라서...) pop
	if (heap.size() > 1) {
		swap(heap[0], heap.back());
	}
	heap.pop_back();
	//힙 조정
	int curIndex = 0;
	int size = heap.size();
	while ((curIndex * 2 + 1) < size) {
		int leftChild = curIndex * 2 + 1;
		int rightChild = curIndex * 2 + 2;
		//자식들 중에서 더 작은 자식 찾기
		int smallest = leftChild;
		if (rightChild < size && heap[rightChild] < heap[leftChild]) {
			smallest = rightChild;
		}
		if (heap[curIndex] <= heap[smallest]) {
			break;
		}
		//바꾸고 이동
		swap(heap[curIndex], heap[smallest]);
		curIndex = smallest;
	}
}

void InsertHeap(int target, vector<int>& heap) {
	heap.push_back(target);
	//힙 조정
	int curIndex = heap.size() - 1;
	while (curIndex > 0) {
		//완전 이진 트리라, 자식 인덱스/2는 항상 부모임
		int parent = (curIndex - 1) / 2;
		//부모와 자식 값 비교 (최소 힙)
		if (heap[curIndex] < heap[parent]) {
			//부모와 자리 바꾸기 (위로 올리기)
			swap(heap[curIndex], heap[parent]);
			curIndex = parent;
		}
		else
			break;
	}
}
//참고 자료: https://twpower.github.io/137-heap-implementation-in-cpp