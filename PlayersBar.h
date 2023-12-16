#ifndef PLAYERSBAR_H
#define PLAYERSBAR_H

class PlayersBar {
private:
    int x, y, originalX, originalY;

public:
    PlayersBar(int posX, int posY);

    void reset();
    void moveUp();
    void moveDown();

    int getX() const;
    int getY() const;

};

#endif // PLAYERSBAR_H
