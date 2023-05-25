#include "GAME.h"
#include <iostream>
using namespace std;
Game::Game() {
}
void Game::startGame() { // 遊戲開始
    cout << "歡迎來到21點遊戲！" << endl;
    cout << "遊戲開始！" << endl;
}
void Game::farmerAsk() { // 玩家要牌
    int cardValue = rand() % 13 + 1;
    pokerF[pokerNumF] = cardValue;
    if (cardValue <= 10)
        cout << "你拿到了一張點數為 " << cardValue << " 的牌。" << endl;
    else
        cout << "你拿到了一張點數為 " << getPokerF(cardValue) << " 的牌。" << endl;
    cout << "玩家的分數為: " <<   playerScore << endl;
}

void Game::landlordAsk() { // 莊家要牌 玩家停牌
    while (dealerScore < 17) {
        int cardValue = rand() % 13 + 1;
        pokerL[pokerNumL] = cardValue;
        if(cardValue <= 10)
            cout << "莊家拿到了一張點數為 " << cardValue << " 的牌。" << endl;
        else
            cout << "莊家拿到了一張點數為 " << getPokerL(cardValue) << " 的牌。" << endl;
    }
}

char Game::getPokerF(int cardValue) { //顯示玩家的牌
    if (cardValue == 11)
        return 'J';
    else if (cardValue == 12)
        return 'Q';
    else if (cardValue == 13)
        return 'K';
}
char Game::getPokerL(int cardValue) { //顯示莊家的牌
    if (cardValue == 11)
        return 'J';
    else if (cardValue == 12)
        return 'Q';
    else if (cardValue == 13)
        return 'K';
}
void Game::displayScore() { // 顯示分數
    cout << "最終結果：" << endl;
    cout << "玩家的分數為: " << playerScore << endl;
    cout << "莊家的分數為: " << dealerScore << endl;
}

bool Game::GameOver() { // 判斷遊戲結束
    if (playerScore > 21) {
        cout << "玩家爆點，莊家勝利！" << endl;
        return true;
    }
    else if (dealerScore > 21) {
        cout << "莊家爆點，玩家勝利！" << endl;
        return true;
    }
    else if (dealerScore >= 17) {
        if (playerScore > dealerScore) {
            cout << "玩家勝利！" << endl;
        }
        else if (playerScore < dealerScore) {
            cout << "莊家勝利！" << endl;
        }
        else {
            cout << "平局！" << endl;
        }
        return true;
    }
    else if (pokerNumF >= 5) {
        std::cout << "玩家手中的牌已達到五張，玩家直接勝利！" << std::endl;
        return true;
    }
    return false;
}
