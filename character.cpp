#include <iostream>
#include "character.h"
#include "Mappa.h"

#define TILE 32



int Personaggio::getY() const {
    return y;
}


int Personaggio::getX() const {
    return x;
}


void Personaggio::DisegnaPersonaggio(RenderWindow &window) {
    window.draw(sprite);
}

void Personaggio::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}


void Personaggio::setPos() {
    if(index!=coordinate.size())
        Personaggio::sprite.setPosition(coordinate[index++]);
}

Personaggio::Personaggio() {
    int xi;
    int yi;
    do {
        xi = static_cast<int>(rand() %  Mappa::crea(1).getColumns());
        yi = static_cast<int>(rand() % Mappa::crea(1).getRows());
    }while (Mappa::crea(1).getTiles(xi,yi) >= 9);
    this->x=xi;
    this->y=yi;
    texture.loadFromFile("./taxi.png");
    sprite.setTexture(texture);
    sprite.scale(0.20,0.20);
    sprite.setPosition(x*TILE,y*TILE);
    index=0;
}

Personaggio &Personaggio::crea() {
    static Personaggio personaggio;
    return personaggio;
}

const vector<Vector2f> &Personaggio::getCoordinate() const {
    return coordinate;
}

void Personaggio::setCoordinate(int x, int y) {
    Personaggio::coordinate.push_back(Vector2f(y,x));
}

int Personaggio::getIndex() const {
    return index;
}

Personaggio::Personaggio(int x, int y) {
    this->x=x;
    this->y=y;
    index=0;
}

Personaggio &Personaggio::crea(int x, int y) {
    static Personaggio personaggio(x,y);
    return personaggio;
}

Mappa Personaggio::MappaP() {
    return Mappa(0);
}
