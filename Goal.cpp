#include "Goal.h"
#include "Mappa.h"
#define TILE 32

Obiettivo::Obiettivo(Mappa *mappa) {
    int xf;
    int yf;
    do {
        xf = static_cast<int>(rand() % mappa->getColumns());
        yf = static_cast<int>(rand() % mappa->getRows());
    }while (mappa->getTiles(xf,yf) >= 9);
    this->x=xf;
    this->y= yf;
    texture.loadFromFile("./goal.png");
    sprite.setTexture(texture);
    sprite.scale(0.20,0.20);
    sprite.setPosition(y*TILE,x*TILE);
}

Obiettivo::~Obiettivo() {}

int Obiettivo::getX() const {
    return x;
}

void Obiettivo::setX(int x) {
    Obiettivo::x = x;
}

int Obiettivo::getY() const {
    return y;
}

void Obiettivo::setY(int y) {
    Obiettivo::y = y;
}

void Obiettivo::setpos(int x, int y) {
    Obiettivo::sprite.setPosition(x,y);
}

void Obiettivo::drawPersonaggio(RenderWindow &window) {
    window.draw(sprite);
}

Obiettivo::Obiettivo(int x, int y) {
    this->x=x;
    this->y= y;
    texture.loadFromFile("./goal.png");
    sprite.setTexture(texture);
    sprite.scale(0.20,0.20);
    sprite.setPosition(y*TILE,x*TILE);
}