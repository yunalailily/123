#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player
{
private:
	int pokerF[5]; //玩家牌
	int pokerNumF; //玩家牌數
public:
	string getPokerF(); //顯示玩家牌
	int getSumF(); //判斷玩家是否>21
	void farmerAsk(); //玩家要牌
	void landlordProcess();
};
#endif 
