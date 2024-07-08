#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
	string name;
	int age;
	//생성자
	Person() {};
};

//객체의 나이 기준으로 오름차순 정렬
bool ASC(const Person &personA,const Person &personB) {
	return personA.age < personB.age;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numOfPeople;
	cin >> numOfPeople;
	Person *People = new Person[numOfPeople];
	for (int i = 0; i < numOfPeople; i++){
		string name;
		int age;
		cin >> age >> name;
		People[i].name = name;
		People[i].age = age;
	}
	//나이 기준 오름차순 정렬
	//stable_sort를 이용하여 나이가 같을 때
	//순서가 바꾸지 않도록 방지
	stable_sort(People, People+ numOfPeople, ASC);

	for (int i = 0; i < numOfPeople; i++){
		cout << People[i].age << " " + People[i].name + "\n";
	}
	return 0;
}