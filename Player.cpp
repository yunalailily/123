#include"Player.h"
#include<string>
#include<iostream>
using namespace std;


string Player::getPokerF() //��ܪ��a�P
{
	int i;
	string result = " ";
	for (int i = 0; i < pokerNumF; i++)
		result += pokerF[i] + " ";
	return result;
}
int Player::getSumF() //�P�_���a�O�_>21
{
	int result = 0;
	for (int i = 0; i < pokerNumF; i++)
		result += pokerF[i];
	return result;
}
void Player::farmerAsk() //���a�n�P
{
	if (pokerNumF >= 5)
	{
		cout << "�L�k�n�P";
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