#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //소숫점자리 6자리 고정
    cout << setprecision(6) << fixed;
    int potions;
    double totalBanguRate = 0.0;
    cin >> potions;
    for (int i = 0; i < potions; i++){
        int newBangMuRate;
        cin >> newBangMuRate;
        //새 방무율 = 기존방무율 + 남은 방어력 * 추가 방무율 -> 기존방무율 + (100.0 - 기존방무) + (추가 방무/100.0)
        totalBanguRate += (100.0 - totalBanguRate) * (newBangMuRate / 100.0);
        cout << totalBanguRate << "\n";
    }
    return 0;
}
