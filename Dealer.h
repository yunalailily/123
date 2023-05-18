#ifndef DEALER_H
#define DEALER_H
#include<string>
using namespace std;
#include <iostream>
#include "Player.h"
class Dealer
{
private:
	Player p;
	int pokerL[5]; //莊家牌
	int pokerNumL; //莊家牌數
public:
	string getPokerL(); //顯示莊家牌
	int getSumL(); //判斷莊家是否>=17
	Dealer();
	void deal();
	int randomCard();
	int getMoreCard();
};
#endif 

