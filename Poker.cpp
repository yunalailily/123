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
	for (int i = 0; i < 52; i++)
	{
		if (poker[i] % 13 < 10) pValue[i] = i % 13 + 1;
		else pValue[i] = 10;
	}
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
	pokerDNum = 0;
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
		sum = sum + pValue[pokerP[i]];

	return sum;
}
int Poker::getSumD() { 
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
			return 0;
		}
		else if (getSumP() == 21)
		{
			cout << "Your cards:" << getPokerP() << endl;
			cout << "You WIN " << endl;
			return 0;
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
			return 0;

		}
		else if (getSumP() == getSumD())
		{
			cout << "PC:" << getPokerD() << endl; 
			cout << getSumD() << " points" << endl;
			cout << "Tie" << endl;
			return 0;
		}
		else if (getSumP() < getSumD())
		{
			cout << "PC:" << getPokerD() << endl; 
			cout << getSumD() << " points" << endl; 
			cout << "You LOSE" << endl;
			return 0;

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
			return 0;
		}
		else    check()

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
			return 0;
		}
		else if (getSumP() == getSumD())  
		{
			cout << "PC:" << getPokerD() << endl;  
			cout << getSumD() << " points" << endl;
			cout << "TIE" << endl;
			return 0;
		}
		else
		{
			cout << "PC:" << getPokerD() << endl; 
			cout << getSumD() << " points" << endl; 
			cout << "You WIN" << endl;
			return 0;
		}
	}
	else
	{
		checkD(); 

	}

}
