#include <iostream>
#include "Poker.h"
using namespace std;

int main()
{
    Poker p;
    int game = 1;
    p.deal();
    cout << "歡迎來到21點" << endl;
    while (game == 1 || game == 2)
    {
        cout << "1.要牌 2.不要牌 3.退出  >>請輸入數字選擇操作:";
        cin >> game;
        if (game == 1) {
            p.checkP();
        }
        else if (game == 2) {
            p.check();
        }
        else      exit(0);
    }
}
