#include"Player.h"
#include<string>
#include<iostream>
using namespace std;


string Player::getPokerF() //顯示玩家牌
{
	int i;
	string result = " ";
	for (int i = 0; i < pokerNumF; i++)
		result += pokerF[i] + " ";
	return result;
}
int Player::getSumF() //判斷玩家是否>21
{
	int result = 0;
	for (int i = 0; i < pokerNumF; i++)
		result += pokerF[i];
	return result;
}
void Player::farmerAsk() //玩家要牌
{
	if (pokerNumF >= 5)
	{
		cout << "無法要牌";
	}
	else
	{
		if (getSumF() > 21)
		{
			cout << "BUST";
		}
		else if (getSumF() == 21)
		{
			landlordProcess();
		}
	}
}