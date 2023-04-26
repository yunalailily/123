#include "Dealer.h"
#include "Player.h"
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
Dealer::Dealer() {
}
void Dealer::deal() {
	cout << "第一輪發牌" << endl << "莊家:";
	int x = randomCard();
	/*while (x > 10) {
		x = randomCard();
	}*/
	cout << x << endl << p.getName() << ":";
	int y = randomCard();
	/*while (y == x || y>10) {
			y = randomCard();
	}*/
	cout<<y<< endl;
	cout << "第二輪發牌" << endl << "*莊家的暗牌被隱藏*" << endl << p.getName() << ":";
	int z = randomCard();
	/*while (z == y || z>10) {
		z = randomCard();
	}*/
	cout<<z<< endl;
}
int Dealer::randomCard(){
	srand(time(0));
	int x = rand() % 13 + 1;
	if (x == 11)
		return 'J';
	else if (x == 12)
		return 'Q';
	else if (x == 13)
		return 'K';
	else
		return x;
}
int Dealer::getMoreCard() {
	char x;
	for (int i = 1; i <= 3; i++) {
		cout << "請問是否要補牌?" << " " << "Y/N" << " ";
		cin >> x;
		if (x == 'N' || x == 'n')
			break;
		else {
			int y = randomCard();
			cout << y << endl;
		}

	}
	return 0;
}