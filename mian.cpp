#include "Dealer.h"
#include "Player.h"
#include <iostream>
using namespace std;
int main() {
	cout << "歡迎來到21點遊戲~" << endl;
	Dealer computer;
	Player p;
	cout << "遊戲開始!" << endl;
	computer.deal();
	computer.getMoreCard();
}
