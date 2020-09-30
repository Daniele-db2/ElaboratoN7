#include <iostream>
#include <cmath>
#include "display.h"
#include "character.h"

#define TILE 32


int main() {
    srand((unsigned int)time(NULL));
    Mappa *mappa = Mappa::crea(1);
    Personaggio p = Personaggio::crea(mappa);
    Obiettivo o = Obiettivo(mappa);
    Schermo schermo = Schermo(mappa);
    string fs = schermo.generaSchermo(o,mappa);
    std::cout<<fs<<endl;
    Event event;
    View view;
    sf::RenderWindow wn(sf::VideoMode(800, 600), "RESULT");
    while (wn.isOpen()) {
        while (wn.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                wn.close();
            }
        }
        wn.setView(view);
        wn.setActive();
        wn.clear();
        sf::Font font;
        if (!font.loadFromFile("./ChickenQuiche.ttf"))
            return 1;
        sf::Text text(fs, font, 50);
        text.setPosition( 0, 400);
        wn.draw(text);
        wn.display();
    }
    return 0;
}