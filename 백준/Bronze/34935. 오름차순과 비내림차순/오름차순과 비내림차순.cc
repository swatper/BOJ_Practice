#include <iostream>
#include <vector>
using namespace std;

bool CheckInc(vector<long long>&array);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int size;
    long long n;
    vector<long long> array;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> n;
        array.push_back(n);
    }
    cout << CheckInc(array) << '\n';
    return 0;
}

bool CheckInc(vector<long long> &array){
    long long pre = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (pre == array[i]) {
            return false;
        }
        pre = array[i];
    }
    return true;
}