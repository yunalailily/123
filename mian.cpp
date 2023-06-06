#include <iostream>
#include "Poker.h"
using namespace std;

int main()
{
    Poker p;
    char card = 'Y';
    p.deal();
    cout << "Welcome to game-POKERFACE" << endl;
    while (card == 'Y' || card == 'N')
    {
        cout << "Ask for a card? Y/N/Q";
        cin >> card;
        if (card == 'Y') {
            p.checkP();//檢查玩家點數和牌數
        }
        else if (card == 'N') {
            p.check();//檢查莊家是超過17點
        }
        else      
            return 0;
    }
}
