#ifndef DEALER_H
#define DEALER_H
#include<string>
using namespace std;

class Dealer
{
private:
	int pokerL[5]; //莊家牌
	int pokerNumL; //莊家牌數
public:
	string getPokerL(); //顯示莊家牌
	int getSumL(); //判斷莊家是否>=17
};
#endif 

