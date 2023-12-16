#include "mbed.h"
#include "Jogador.h"


Jogador::Jogador(float y, int score) :
    y(y), score(score), mutex(){};

float Jogador::getY() {
    return y;
}

int Jogador::getScore() {
    return score;
}

void Jogador::setY(float newY) {
    mutex.lock();
    y = newY;
    mutex.unlock();
}

void Jogador::setScore(int newScore) {
    mutex.lock();
    score = newScore;
    mutex.unlock();
}
