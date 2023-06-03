#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <array>
#include "Poker.h"
using namespace std;
Poker::Poker()//撲克設定初值
{
	for (int i = 0; i < 52; i++)//設定52張牌的牌面為0~51
	{
		poker[i] = i;
	}
	for (int i = 0; i < 52; i++)//設定不顯示的52張牌的分數
	{
		if (poker[i] % 13 < 10) //A~10,J,Q,K共13種點數所以mod13 若小於10則為A~10(A=1點,其餘依照牌面)
			pValue[i] = i % 13 + 1;//+1因為從0開始
		else pValue[i] = 10;//J,Q,K分數計算為10點
	}
	const string pokerNumber[13] =//設定會顯示的撲克牌牌面
	{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	for (int i = 0; i < 52; i++)
	{
		int j = i % 13;//不用+1因為不是算點數(j=0~12)
		pName[i] = pokerNumber[j];
	}

	for (int i = 0; i < 5; i++)//莊家跟玩家一共五張牌 設定初值=0
	{
		pokerP[i] = 0;
		pokerD[i] = 0;
	}
	pokerPNum = 0;//設定玩家總分=0
	pokerDNum = 0;//設定莊家總分=0
}

void Poker::deal()
{
	int k, tem;
	srand(time(0));
	for (int i = 52; i > 0; i--)
	{
		k = rand() % 52;
		tem = poker[k];
		poker[k] = poker[i];
		poker[i] = tem;
	}
}

int Poker::getSumP() {
	int sum = 0;

	for (int i = 0; i < pokerPNum; i++)
		sum = sum + pValue[pokerP[i]];//poker[P[i]]=玩家的第?張牌//pValue[pokerP[i]]=第?張牌的點數加至sum中

	return sum;
}
int Poker::getSumD() {//莊家的總點數 同上
	int sum = 0;

	for (int i = 0; i < pokerDNum; i++)
		sum = sum + pValue[pokerD[i]];

	return sum;
}
string Poker::getPokerP() {
	string result = "";

	for (int i = 0; i < pokerPNum; i++)
		result = result + pName[pokerP[i]] + " ";

	return result;
}
string Poker::getPokerD() {
	string result = "";

	for (int i = 0; i < pokerDNum; i++)
		result = result + pName[pokerD[i]] + " ";

	return result;
}

void Poker::checkP() {
	if (pokerPNum >= 5)
	{
		cout << "You already have 5 cards" << endl;
	}
	else
	{
		pokerP[pokerPNum++] = rand() % 52;
		cout << "You:" << getPokerP() << endl;
		cout << getSumP() << " points" << endl;
		if (getSumP() > 21)
		{

			cout << "You LOSE" << endl;
			cout << "Game over" << endl;
			exit(0);
		}
		else if (getSumP() == 21)
		{
			cout << "Your cards:" << getPokerP() << endl;
			cout << "You WIN " << endl;
			exit(0);
		}


	}
}
void Poker::checkD() {
	if (pokerDNum >= 5)
	{
		if (getSumP() > getSumD())
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "You WIN" << endl;
			exit(0);

		}
		else if (getSumP() == getSumD())
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "Tie" << endl;
			exit(0);
		}
		else if (getSumP() < getSumD())
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "You LOSE" << endl;
			exit(0);

		}
	}
	else
	{
		pokerD[pokerDNum++] = rand() % 52;
		if (getSumD() > 21)
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "You WIN" << endl;
			exit(0);
		}
		else    
			check();

	}
}

void Poker::check() {
	if (getSumD() >= 17)
	{
		if (getSumD() > getSumP())
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "You LOSE" << endl;
			exit(0);
		}
		else if (getSumP() == getSumD())
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "TIE" << endl;
			exit(0);
		}
		else
		{
			cout << "PC:" << getPokerD() << endl;
			cout << getSumD() << " points" << endl;
			cout << "You WIN" << endl;
			exit(0);
		}
	}
	else
	{
		checkD();

	}

}
