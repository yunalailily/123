#pragma once
#include <iostream>
#include "Player.h"
using namespace std;
class Dealer {
private:
	Player p;
public:
	Dealer();
	void deal();
	int randomCard();
	int getMoreCard();
};
