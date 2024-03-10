#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	float Avg = 0.0; 
	int Subjects, Highest = -1;
	cin >> Subjects;
	float* SubjectArray = new float[Subjects];
	for (int i = 0; i < Subjects; i++) {
		cin >> SubjectArray[i];
		if (Highest < SubjectArray[i]) {
			Highest = SubjectArray[i];
		}
	}
	for (int i = 0; i < Subjects; i++) {
		Avg += (SubjectArray[i] / Highest) * 100;
	}
	Avg = Avg / Subjects;
	cout << Avg << "\n";
	delete[] SubjectArray;
	return 0;
}