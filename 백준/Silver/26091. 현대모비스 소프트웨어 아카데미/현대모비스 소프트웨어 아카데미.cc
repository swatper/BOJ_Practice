#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> StudentsAbility;
	int Students, ReqAbility,Ability ,Group = 0;
	cin >> Students >> ReqAbility;
	for (int i = 0; i < Students; i++){
		//학생의 능력치 입력받고
		cin >> Ability;
		//배열에 추가
		StudentsAbility.push_back(Ability);
	}
	//오름차순으로 정렬
	sort(StudentsAbility.begin(), StudentsAbility.end());
	//계산하기
	int Front = 0, Back = StudentsAbility.size() - 1;
	while (Front < Back){
		//가장 능력치가 높은 학생과 가장 낮은 학생의 합 구하기(팀원은 2명)
		int AbilitySum = StudentsAbility[Front] + StudentsAbility[Back];
		//합이 요구하는 능력치보다 작으면 가장 낮은 학생의 다음 학생을 선택해야 함
		if (AbilitySum < ReqAbility){
			Front++;
		}
		//합이 요구하는 능력치보다 크면 양 끝의 다음 학생을 선택
		else {
			Front++;
			Back--;
			Group++;
		}
	}
	//결과 확인
	cout << Group << "\n";
	return 0;
}    