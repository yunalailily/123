#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player
{
private:
	int pokerF[5]; //���a�P
	int pokerNumF; //���a�P��
public:
	string getPokerF(); //��ܪ��a�P
	int getSumF(); //�P�_���a�O�_>21
	void farmerAsk(); //���a�n�P
	void landlordProcess();
};
#endif 
