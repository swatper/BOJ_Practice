#include <iostream>
using namespace std; 

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int numSwitches, numStudents, studentGender, getSwitches;
	int count = 0;
	cin >> numSwitches;
	//스위치 상태를 저장할 배열
	bool* switchStatus = new bool[numSwitches + 1];
	//스위치 상태 입력 받기
	for (int i = 1; i <= numSwitches; i++) {
		//입력받을 때 0이면 false 나미저는 true
		cin >> switchStatus[i];
	}
	cin >> numStudents;
	//학생 수 만큼 반복
	for (int i = 0; i < numStudents; i++) {
		cin >> studentGender >> getSwitches;
		if (studentGender == 1) { //남학생일 경우
			for (int a = 1; a <= numSwitches; a++) { //스위치 조작
				if (a % getSwitches == 0 ) { //스위치 번호가 자기가 받은 수의 배수
					switchStatus[a] = !switchStatus[a]; //반전 시켜서 저장
				}
			}
		}
		else if (studentGender == 2){					//여학생일 경우
			switchStatus[getSwitches] = !switchStatus[getSwitches];	//본인꺼 바꾸기
			for (int a = 1; a <= numSwitches; a++) {
				if (getSwitches - a >= 1 && getSwitches + a <= numSwitches) {			 //범위 확인
					if (switchStatus[getSwitches - a] == switchStatus[getSwitches + a]) {//가운데 기준 양쪽 비교
						switchStatus[getSwitches - a] = !switchStatus[getSwitches - a];
						switchStatus[getSwitches + a] = !switchStatus[getSwitches + a];
					}
					else {
						break;
					}
				}
				else {
					break;
				}
			}
		}
	}
	for (int i = 1; i <= numSwitches; i++) {
		cout << switchStatus[i]<<" ";
		count++;
		//문제에서 스위치 20개당 한 줄씩 출력해라 했음
		if (count % 20 == 0) {
			cout << "\n";
		}		
	}
	return 0;
}