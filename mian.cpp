#include "Dealer.h"
#include "Player.h"
#include <iostream>
using namespace std;
int main() {
	cout << "歡迎來到21點遊戲~" << endl << "請輸入玩家姓名:";
	string n;
	cin >> n;
	Dealer computer;
	Player p;
	p.setName(n);
	cout << "遊戲開始!" << endl;
	computer.deal();
	computer.getMoreCard();
}