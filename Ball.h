#ifndef BALL_H
#define BALL_H

enum class EDirection {
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6
};

class Ball {
private:
    int x, y, originalX, originalY;
    EDirection direction;

public:
    Ball(int posX, int posY);

    void reset();
    void changeDirection(EDirection d);
    void randomDirection();
    void move();

    int getX() const;
    int getY() const;
    EDirection getDirection() const;

};

#endif // BALL_H
