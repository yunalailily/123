#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <array>
#include "Poker.h"
using namespace std;
Poker::Poker()
{
	int i = 0;
	poker[0] = 0;
	for (i = 0; i < 52; i++)
	{
		poker[i] = i;
	}
	//poker value
	for (int i = 0; i < 52; i++)
	{
		if (poker[i] % 13 < 10) pValue[i] = i % 13 + 1;
		else pValue[i] = 10;
	}
	//poker number
	const string pokerNumber[13] =
	{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	for (int i = 0; i < 52; i++)
	{
		int j = i % 13;
		pName[i] = pokerNumber[j];
	}

	for (i = 0; i < 5; i++)
	{
		pokerP[i] = 0;
		pokerD[i] = 0; //(pokerB[i])
	}
	pokerPNum = 0;
	pokerDNum = 0; // (pokerBNum)
}

void Poker::deal() //(shuffle())
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
		sum = sum + pValue[pokerP[i]];

	return sum;
}
int Poker::getSumD() {  //(getSumB)
	int sum = 0;

	for (int i = 0; i < pokerDNum; i++) //(pokerBNum)
		sum = sum + pValue[pokerD[i]]; //(pokerB[i])

	return sum;
}
string Poker::getPokerP() {
	string result = "";

	for (int i = 0; i < pokerPNum; i++)
		result = result + pName[pokerP[i]] + " ";

	return result;
}
string Poker::getPokerD() { //(getPokerB)
	string result = "";

	for (int i = 0; i < pokerDNum; i++) //(pokerBNum)
		result = result + pName[pokerD[i]] + " "; //(pokerB[i])

	return result;
}

void Poker::checkP() { //(outs)
	if (pokerPNum >= 5)
	{
		cout << "你的牌數已達上限" << endl;
	}
	else
	{
		pokerP[pokerPNum++] = rand() % 52;
		cout << "你的牌為:" << getPokerP() << endl;
		cout << getSumP() << "點" << endl;
		if (getSumP() > 21)
		{

			cout << "你已經輸了" << endl;
			cout << "遊戲結束" << endl;
			exit(0);
		}
		else if (getSumP() == 21)
		{
			cout << "玩家的牌為" << getPokerP() << endl;
			cout << "你贏了 " << endl;
			exit(0);
		}


	}
}
void Poker::checkD() { //(Bouts)
	if (pokerDNum >= 5) //(pokerBNum)
	{
		if (getSumP() > getSumD())  //(getSumB)
		{
			cout << "莊家的牌為" << getPokerD() << endl; //(getPokerB)
			cout << getSumD() << "點" << endl; //(getSumB)
			cout << "你贏了" << endl;
			exit(0);

		}
		else if (getSumP() == getSumD())//(getSumB)
		{
			cout << "莊家的牌為" << getPokerD() << endl; //(getPokerB)
			cout << getSumD() << "點" << endl; //(getSumB)
			cout << "平手" << endl;
			exit(0);
		}
		else if (getSumP() < getSumD())
		{
			cout << "莊家的牌為" << getPokerD() << endl;  //(getPokerB)
			cout << getSumD() << "點" << endl;  //(getSumB)
			cout << "你輸了" << endl;
			exit(0);

		}
	}
	else
	{
		pokerD[pokerDNum++] = rand() % 52; //(pokerB[pokerBNum++])
		if (getSumD() > 21)  //(getSumB)
		{
			cout << "莊家的牌為" << getPokerD() << endl;  //(getPokerB)
			cout << getSumD() << "點" << endl; //(getSumB)
			cout << "莊家死了,你贏了" << endl;
			exit(0);
		}
		else    check(); //(BBouts)

	}
}

void Poker::check() { //(BBouts)
	if (getSumD() >= 17) //(getSumB)
	{
		if (getSumD() > getSumP()) //(getSumB)
		{
			cout << "莊家的牌為" << getPokerD() << endl; //(getPokerB())
			cout << getSumD() << "點" << endl; //(getSumB)
			cout << "你輸了" << endl;
			exit(0);
		}
		else if (getSumP() == getSumD())  //(getSumB)
		{
			cout << "莊家的牌為" << getPokerD() << endl;  //(getPokerB())
			cout << getSumD() << "點" << endl; //(getSumB)
			cout << "你輸了" << endl;
			exit(0);
		}
		else
		{
			cout << "莊家的牌為" << getPokerD() << endl;  //(getPokerB())
			cout << getSumD() << "點" << endl;  //(getSumB)
			cout << "你贏了" << endl;
			exit(0);
		}
	}
	else
	{
		checkD();  //(Bouts)

	}

}
