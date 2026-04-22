#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int value;
	Node* Left;
	Node* Right;

	//생성자
	Node(int v) {
		value = v;
		Left = nullptr;
		Right = nullptr;
	}
};

Node* InsertNode(Node* root, int v);
void PostOrder(Node *root);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int value, index = 0;
	Node* root = nullptr;
	//트리 만들기
	while (cin >> value) 
		root = InsertNode(root, value);

	//후위 탐색
	PostOrder(root);
	return 0;
}

Node* InsertNode(Node* root, int v){
	Node* newNode = new Node(v);
	if (root == NULL)
		return newNode;

	//자식 확인
	Node *curParent = root;
	while (true) {
		if (curParent->value < v) {
			if (curParent->Right == nullptr) {
				curParent->Right = newNode;
				break;
			}
			curParent = curParent->Right;
		}
		else {
			if (curParent->Left == nullptr) {
				curParent->Left = newNode;
				break;
			}
			curParent = curParent->Left;
		}
	}
	return root;
}

void PostOrder(Node* root) {
	if (root == nullptr)
		return;
	PostOrder(root ->Left);
	PostOrder(root ->Right);
	cout << root->value << '\n';
}