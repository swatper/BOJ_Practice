#include <iostream>
using namespace std;

void RecursiveFunction(int questions,int * count, const string *sentences);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//질문/답변 문장
	string sentences[6] = {"\"재귀함수가 뭔가요?\"\n", 
						  "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
						  "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", 
						  "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n",
						  "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
						  "라고 답변하였지.\n"};
	int questions, count = 0;
	cin >> questions;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	//재귀 시작
	RecursiveFunction((questions + 1), &count, sentences);
	return 0;
}    

void RecursiveFunction(int questions, int* count, const string* sentences) {
	string underbar;
	for (int i = 1; i <= (*count); i++) {
		underbar += "____";
	}
	//포인터 사용
	(*count)++;
	cout << underbar + sentences[0];
	//마지막 질문에 대한 답변
	if ((*count) == questions) {
		cout << underbar + sentences[4];
	}
	//질문(재귀)
	else {
		cout << underbar + sentences[1];
		cout << underbar + sentences[2];
		cout << underbar + sentences[3];
		RecursiveFunction(questions, count, sentences);
	}
	//마지막 문장
	cout << underbar + sentences[5];
}