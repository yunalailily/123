#ifndef POKER_H
#define POKER_H
#include <string>
using namespace std;
class Poker
{
private:
	int poker[52];
	int pValue[52];
	string pName[52];
	int pokerP[5]; //玩家牌
	int pokerD[5]; //莊家牌(pokerB)
	int pokerPNum; //玩家牌數
	int pokerDNum; //莊家牌數(pokerBNum)

public:
	Poker();
	void deal(); //發牌  (shuffle())
	int getSumP(); //玩家牌加總
	int getSumD(); //莊家牌加總(getSumB())
	string getPokerP(); //顯示玩家牌
	string getPokerD(); //顯示莊家牌(getPokerB())
	void checkP(); //檢查玩家牌 (outs)
	void checkD(); //檢查莊家牌 (Bouts)
	void check(); //檢查 (BBouts)
};
#endif
