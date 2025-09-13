#include <iostream>
using namespace std;

void CheckEscapable(string classSchedule);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int teachers, classes;
	cin >> teachers >> classes;
	//classes길이의 문자열을 '-'로 초기화
	string classSchedule(classes, 'X');
	for (int i = 0; i < teachers; i++) {
		string teacharSchedule;
		cin >> teacharSchedule;
		for (int j = 0; j < classes; j++) {
			if (teacharSchedule[j] == 'X')
				continue;
			classSchedule[j] = teacharSchedule[j];
		}
	}
	CheckEscapable(classSchedule);
	return 0;
}

void CheckEscapable(string classSchedule) {
	int escapeTime = 101;
	bool escapable = false;
	for (int i = 0; i < classSchedule.length(); i++){
		if (classSchedule[i] == 'X') {
			escapable = true;
			escapeTime = i;
			break;
		}
	}
	if (!escapable)
		cout << "ESCAPE FAILED \n";
	else
		cout << escapeTime + 1 << "\n";
}
