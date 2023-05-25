#ifndef GAME_H
#define GAME_H

class Game {
private:
    int playerScore; // 玩家總分
    int dealerScore; // 莊家總分
    int pokerF[5]; // 玩家手中的牌
    int pokerL[5]; // 莊家手中的牌
    int pokerNumF; // 玩家手中的牌數
    int pokerNumL; // 莊家手中的牌數
public:
    void startGame();     // 遊戲開始
    void farmerAsk();     // 玩家要牌
    void landlordAsk();   // 莊家要牌 玩家停牌
    char getPokerF(int);   // 顯示玩家的牌
    char getPokerL(int);   // 顯示莊家的牌
    void displayScore();  // 顯示分數
    bool GameOver();      // 判斷遊戲結束
};

#endif
