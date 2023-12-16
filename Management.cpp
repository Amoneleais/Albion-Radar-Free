#include "Management.h"
#include "Jogador.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Management::Management(int w, int h, Jogador * jogador1, Jogador * jogador2) 
    : width(w), height(h), score1(0), score2(0), ball(w / 2, h / 2), player1(1, h / 2 - 3), player2(w - 2, h / 2 - 3) {
            this->jogador_1 = jogador1;
            this->jogador_2 = jogador2;
    srand(time(NULL));
}

void Management::scoreUp(PlayersBar &player) {
    if (&player == &player1) {
        score1++;
    } else {
        score2++;
    }
    ball.reset();
    player1.reset();
    player2.reset();
}

void Management::resetGame() {
    // Não verifica, apenas reseta o jogo 
    ball.reset();
    player1.reset();
    player2.reset();
}

inline void Management::setTextColor(const char* color) {
    // função para mudar a cor do texto de acordo com o valor
    printf("%s", color);
}

inline void Management::setBackgroundColor(const char* color) {
    // função para mudar a cor do fundo com o valor
    printf("%s", color);
}


void Management::drawBoard() {
    cout << "\033[2J\033[H";
        cout << "\033[H";

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int ballx = ball.getX();
                int bally = ball.getY();
                int player1x = player1.getX();
                int player2x = player2.getX();

                int player1y = player1.getY();
                int player2y = player2.getY();

                if (j == 0 || j == width - 2) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_AZUL);
                    cout << BLANK_SPACE;
                } else if (ballx == j && bally == i) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << BALL;
                } else if ((player1x + 1 == j || player1x + 2 == j) && i >= player1y && i < player1y + 4) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << PLAYER_BAR;
                } else if ((player2x - 1 == j || player2x - 2 == j) && i >= player2y && i < player2y + 4) {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_BRANCO);
                    cout << PLAYER_BAR;
                } else {
                    setBackgroundColor(BG_AZUL);
                    setTextColor(TXT_AZUL);
                    cout << BLANK_SPACE;
                }
            }
            cout << RESET << endl;
        }
}

void Management::movePlayers() {
    ball.move();

    int ballx = ball.getX();
    int bally = ball.getY();
    int player1x = player1.getX();
    int player2x = player2.getX();
    int player1y = player1.getY();
    int player2y = player2.getY();

    if (jogador_1->getY() > 0.8 && player1y > 0) {
        player1.moveUp();
    } else if (jogador_1->getY() < 0.3 && player1y + 4 < height) {
        player1.moveDown();
    }

    if (jogador_2->getY() > 0.8 && player2y > 0) {
        player2.moveUp();
    } else if (jogador_2->getY() < 0.3 && player2y + 4 < height) {
        player2.moveDown();
    }

    if (ball.getDirection() == EDirection::STOP) {
        ball.randomDirection();
    }
}

void Management::check() {
    // Fazer as colisões
    int ballx = ball.getX();
    int bally = ball.getY();
    int player1x = player1.getX();
    int player2x = player2.getX();

    int player1y = player1.getY();
    int player2y = player2.getY();

    // Colisão com jogador 1
    if (ballx == player1x + 2 && bally >= player1y && bally <= player1y + 3) {
        ball.move(); // Adicionei um movimento para que a bola não fique presa no jogador
        ball.changeDirection(static_cast<EDirection>((rand() % 3) + 4));
    }

    // Colisão com jogador 2
    if (ballx == player2x - 2 && bally >= player2y && bally <= player2y + 3) {
        ball.move(); // Adicionei um movimento para que a bola não fique presa no jogador
        ball.changeDirection(static_cast<EDirection>((rand() % 3) + 1));
    }

    // Limite superior
    if (bally == 0) {
        ball.changeDirection(static_cast<EDirection>(ball.getDirection() == EDirection::UPRIGHT ? EDirection::DOWNRIGHT : EDirection::DOWNLEFT));
    }

    // Limite inferior
    if (bally == height - 1) {
        ball.changeDirection(static_cast<EDirection>(ball.getDirection() == EDirection::DOWNRIGHT ? EDirection::UPRIGHT : EDirection::UPLEFT));
    }

    // Colisões laterais (incrementar score dos players)
    // Parede direita
    if (ballx == width - 1) {
        scoreUp(player1);
    }

    // Parede esquerda
    if (ballx == 0) {
        scoreUp(player2);
    }
}

void Management::run() {
    drawBoard();
    movePlayers();
    check();
    setBackgroundColor(BG_PRETO);
    setTextColor(TXT_AMARELO);
    printf("\nSCORE\nPlayer1: %i  ----------------------------------------------------------------- Player2: %i\n\n", score1, score2);
    
    setBackgroundColor(RESET);
    setTextColor(RESET);
}
