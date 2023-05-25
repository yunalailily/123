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
            p.checkP();
        }
        else if (card == 'N') {
            p.check();
        }
        else      
            return 0;
    }
}
