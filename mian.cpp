#include "Dealer.h"
#include "Player.h"
#include <iostream>
using namespace std;
int main() {
	cout << "�w��Ө�21�I�C��~" << endl << "�п�J���a�m�W:";
	string n;
	cin >> n;
	Dealer computer;
	Player p;
	p.setName(n);
	cout << "�C���}�l!" << endl;
	computer.deal();
	computer.getMoreCard();
}