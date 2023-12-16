#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Ball.h"
#include "PlayersBar.h"
#include "Jogador.h"
#include "mbed.h"

#define TXT_AZUL        "\033[34m"
#define TXT_BRANCO      "\033[97m"
#define TXT_AMARELO     "\033[33m"

// definir backgroud
#define BG_AZUL         "\033[44m"
#define BG_BRANCO       "\033[107m"
#define BG_PRETO        "\033[40m"

// definir reset
#define RESET           "\033[0m"

// definir componentes
#define BALL            "O"
#define BLANK_SPACE     " "
#define PLAYER_BAR      "\xDB"

class Management {
private:
    int width, height;
    int score1, score2;
    Ball ball;
    PlayersBar player1;
    PlayersBar player2;
    Jogador * jogador_1;
    Jogador * jogador_2;
public:
    Management(int w, int h, Jogador * jogador1, Jogador * jogador2);
    void scoreUp(PlayersBar &player);
    inline void setTextColor(const char* color);
    inline void setBackgroundColor(const char* color);
    void resetGame();
    void drawBoard();
    void movePlayers();
    void check();
    void run();
};

#endif // MANAGEMENT_H
