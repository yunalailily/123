#include"Dealer.h"
#include<string>
using namespace std;


string Dealer::getPokerL() //��ܲ��a�P
{
	int i;
	string result = " ";
	for (int i = 0; i < pokerNumL; i++)
		result += pokerL[i];
	return result;
}
int Dealer::getSumL() //�P�_���a�O�_>=17
{
	int result = 0;
	for (int i = 0; i < pokerNumL; i++)
		result += pokerL[i];
	return result;
}
