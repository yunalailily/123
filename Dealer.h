#ifndef DEALER_H
#define DEALER_H
#include<string>
using namespace std;

class Dealer
{
private:
	int pokerL[5]; //���a�P
	int pokerNumL; //���a�P��
public:
	string getPokerL(); //��ܲ��a�P
	int getSumL(); //�P�_���a�O�_>=17
};
#endif 

