#include <iostream>
using namespace std;

int GetMonthDates(int targetYear, int targetMonth);
int GetTotalDates(int targetYear, int targetMonth, int targetDate);
bool IsLeap(int targetYear);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int result = 0;
	int curYear, targetYear, curMonth, targetMonth, curDate, targetDate;
	cin >> curYear >> curMonth >> curDate;
	cin >> targetYear >> targetMonth >> targetDate;
	bool isGG = false;
	if (targetYear - curYear > 1000){
		isGG = true;
	}
	else if (targetYear - curYear == 1000) {
		if (targetMonth > curMonth)
			isGG = true;
		else if (targetMonth == curMonth && targetDate >= curDate)
			isGG = true;
	}

	if (isGG)
		cout << "gg" << '\n';
	else {
		result = GetTotalDates(targetYear, targetMonth, targetDate) - GetTotalDates(curYear, curMonth, curDate);
		cout << "D-" << result << '\n';
	}

	return 0;
}

int GetMonthDates(int targetYear, int targetMonth) {
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int correction = targetMonth - 1;
	if (targetMonth == 2 && IsLeap(targetYear))
		return 29;
	return days[correction];
}

int GetTotalDates(int targetYear, int targetMonth, int targetDate) {
	int total = 0;
	for (int i = 1; i < targetYear; i++)
		total += IsLeap(i) ? 366 : 365;

	for (int i = 1; i < targetMonth; i++)
		total += GetMonthDates(targetYear, i);

	total += targetDate;
	return total;
}

bool IsLeap(int targetYear) {
	if (targetYear % 400 == 0)
		return true;
	if(targetYear % 100 == 0)
		return false;
	if (targetYear % 4 == 0)
		return true;
	return false;
}