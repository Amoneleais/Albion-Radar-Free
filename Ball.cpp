#include "Ball.h"
#include <cstdlib>

Ball::Ball(int posX, int posY)
    : originalX(posX), originalY(posY), x(posX), y(posY), direction(EDirection::STOP) {}

void Ball::reset() {
    x = originalX;
    y = originalY;
    direction = EDirection::STOP;
}

void Ball::changeDirection(EDirection d) {
    direction = d;
}

void Ball::randomDirection() {
    direction = static_cast<EDirection>(rand() % 6 + 1);
}

void Ball::move() {
    switch (direction) {
        case EDirection::STOP:
            break;
        case EDirection::LEFT:
            x--;
            break;
        case EDirection::UPLEFT:
            x--;
            y--;
            break;
        case EDirection::RIGHT:
            x++;
            break;
        case EDirection::DOWNLEFT:
            x--;
            y++;
            break;
        case EDirection::UPRIGHT:
            x++;
            y--;
            break;
        case EDirection::DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
    }
}

int Ball::getX() const {
    return x;
}

int Ball::getY() const {
    return y;
}

EDirection Ball::getDirection() const {
    return direction;
}
