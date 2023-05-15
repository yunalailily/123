#include"Dealer.h"
#include<string>
using namespace std;


string Dealer::getPokerL() //顯示莊家牌
{
	int i;
	string result = " ";
	for (int i = 0; i < pokerNumL; i++)
		result += pokerL[i];
	return result;
}
int Dealer::getSumL() //判斷莊家是否>=17
{
	int result = 0;
	for (int i = 0; i < pokerNumL; i++)
		result += pokerL[i];
	return result;
}
