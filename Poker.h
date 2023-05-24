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
	int pokerP[5]; //���a�P
	int pokerD[5]; //���a�P(pokerB)
	int pokerPNum; //���a�P��
	int pokerDNum; //���a�P��(pokerBNum)

public:
	Poker();
	void deal(); //�o�P  (shuffle())
	int getSumP(); //���a�P�[�`
	int getSumD(); //���a�P�[�`(getSumB())
	string getPokerP(); //��ܪ��a�P
	string getPokerD(); //��ܲ��a�P(getPokerB())
	void checkP(); //�ˬd���a�P (outs)
	void checkD(); //�ˬd���a�P (Bouts)
	void check(); //�ˬd (BBouts)
};
#endif
