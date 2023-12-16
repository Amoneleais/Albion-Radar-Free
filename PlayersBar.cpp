#include "PlayersBar.h"

PlayersBar::PlayersBar(int posX, int posY)
    : originalX(posX), originalY(posY), x(posX), y(posY) {}

void PlayersBar::reset() {
    x = originalX;
    y = originalY;
}

void PlayersBar::moveUp() {
    y--;
}

void PlayersBar::moveDown() {
    y++;
}

int PlayersBar::getX() const {
    return x;
}

int PlayersBar::getY() const {
    return y;
}
