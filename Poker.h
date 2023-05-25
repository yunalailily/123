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
	int pokerP[5]; 
	int pokerD[5];
	int pokerPNum; 
	int pokerDNum; 

public:
	Poker();
	void deal(); 
	int getSumP();
	int getSumD();
	string getPokerP(); 
	string getPokerD(); 
	void checkP(); 
	void checkD(); 
	void check(); 
};
#endif
