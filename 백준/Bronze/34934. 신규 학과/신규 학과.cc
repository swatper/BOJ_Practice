#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    
    int majors, year;
    string majorName, result;
    cin >> majors;
    for(int i = 0; i < majors; i++){
        cin >> majorName >> year;
        if (year == 2026) {
            result = majorName;
        }
    }
    cout << result << '\n';
    return 0;
}