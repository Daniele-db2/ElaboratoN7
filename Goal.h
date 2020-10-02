#ifndef ELABORATO_N7_GOAL_H
#define ELABORATO_N7_GOAL_H

#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics.hpp>
#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics/Sprite.hpp>
#include "Mappa.h"

using namespace sf;



class Obiettivo {
public:
    explicit Obiettivo();
    Obiettivo(int x,int y);
    virtual ~Obiettivo();
    void drawPersonaggio(RenderWindow &window);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setpos(int x, int y);

private:
    Texture texture;
    Sprite sprite;
    int x;
    int y;

};

#endif //ELABORATO_N7_GOAL_H