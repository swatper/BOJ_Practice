#include <string>
#include <vector>
#include <set>
using namespace std;

bool FindPair(set<int>& deck1, set<int> deck2, int target) {
    for (int card : deck1) {
        int needCard = target - card;
        //(목표값 - 현재 카드 값)의 값이 있는지 확인 (현재 값 + 찾는 값 = 목표값 보다 쉬움)
        if (deck2.find(needCard) != deck2.end()) {
            //카드 사용
            deck1.erase(card);
            deck2.erase(needCard);
            return true;
        }
    }
    //조합 찾기 실패
    return false;
}


int solution(int coin, vector<int> cards) {
    int answer = 1;
    int deckSize = cards.size();
    int targetNumber = deckSize + 1;
    int drowingCardIndex = deckSize / 3;
    set<int> hands;
    set<int> drowHands;
    //게임 시작 카드 드로우!
    for (int card = 0; card < drowingCardIndex ; card++)
        hands.insert(cards[card]);
    //턴 시작!
    while (drowingCardIndex < deckSize) {

        //카드 두장 드로우!
        drowHands.insert(cards[drowingCardIndex++]);
        drowHands.insert(cards[drowingCardIndex++]);
        //무조건 조합 카드를 찾아야 함
            //코인 소비 안 하고 조합 찾기(헨드 2장 사용)
        if (FindPair(hands, hands, targetNumber)) {
            answer++;
            continue;
        }
            //코인 1개 쓰고 조합 찾기 (헨드1장 and 드로우 1장 사용) 
        if (coin>= 1 && FindPair(hands, drowHands, targetNumber)) {
            coin--;
            answer++;
            continue;
        }
            //코인 2개 쓰고 조합 찾기 (드로우 2장 사용)
        if (coin >= 2 && FindPair(drowHands, drowHands, targetNumber)) {
            coin -= 2;
            answer++;
            continue;
        }
            //카드 못 찾으면 종료
        break;
    }
    return answer;
}