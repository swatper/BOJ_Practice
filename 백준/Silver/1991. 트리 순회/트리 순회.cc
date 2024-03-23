#include <iostream>
using namespace std;

//전위 탐색 (출력, 왼쪽 확인, 오른쪽 확인)
class Node
{
public:
	char NodeName;
	//각 자식 노드의 주소를 저장
	Node* LeftNode;
	Node* RightNode;
	Node();
	~Node();
};
//객체 기본 생성자
Node::Node() {}
//객체 기본 소멸자
Node::~Node() {}

//전위 탐색(출력, 왼쪽 확인, 오른쪽 확인)
void PreorderTrav(Node * RootNode) {
	cout << RootNode->NodeName;

	if (RootNode->LeftNode != NULL) {
		PreorderTrav(RootNode->LeftNode); //재귀
	}
	if (RootNode->RightNode != NULL) {
		PreorderTrav(RootNode->RightNode); //재귀
	}
	return;
}
//중위 탐색(왼쪽 확인, 출력, 오른쪽 확인)
void InoderTrav(Node* RootNode) {
	if (RootNode->LeftNode != NULL) {
		InoderTrav(RootNode->LeftNode); //재귀
	}

	cout << RootNode->NodeName;

	if (RootNode->RightNode != NULL) {
		InoderTrav(RootNode->RightNode); //재귀
	}
	return;
}
//후위 탐색(왼쪽 확인, 오른쪽 확인, 출력)
void PostorderTrav(Node* RootNode) {
	if (RootNode->LeftNode != NULL) {
		PostorderTrav(RootNode->LeftNode); //재귀
	}

	if (RootNode->RightNode != NULL) {
		PostorderTrav(RootNode->RightNode); //재귀
	}

	cout << RootNode->NodeName;
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Nodes;
	cin >> Nodes;
	//객체 배열 생성
	Node Node[27];
	for (int i = 0; i < Nodes; i++) {
		char Root, Left, Right;
		cin >> Root >> Left >> Right;
		//0번째 노드를 A로 생각하여 각 노드의 자식 노드들을 연결
		Node[Root - 'A'].NodeName = Root;
		if (Left == '.') {
			Node[Root - 'A'].LeftNode = NULL;
		}
		else {
			Node[Root - 'A'].LeftNode = &Node[Left - 'A'];
		}

		if (Right == '.') {
			Node[Root - 'A'].RightNode = NULL;
		}
		else {
			Node[Root - 'A'].RightNode = &Node[Right - 'A'];
		}
		
	}
	//순회 출력
	PreorderTrav(&Node[0]);
	cout << "\n";
	InoderTrav(&Node[0]);
	cout << "\n";
	PostorderTrav(&Node[0]);
	cout << "\n";

	return 0;
}