#ifndef JOGADOR_H
#define JOGADOR_H

#include "mbed.h"

class Jogador {
private:
    float y;
    int score;
    Mutex mutex;
public:;
    Jogador(float y, int score);
    void setY(float y);
    float getY();
    int getScore();
    void setScore(int score);
};

#endif // JOGADOR_H
