#ifndef ELABORATO_N7_DISPLAY_H
#define ELABORATO_N7_DISPLAY_H

#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics.hpp>
#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics/RenderWindow.hpp>
#include "Goal.h"
#include "Mappa.h"
#include "character.h"

using namespace sf;

class Schermo {
public:
    explicit Schermo(Mappa *mappa);
    ~Schermo();
    string generaSchermo(Obiettivo obiettivo, Mappa *mappa);
    string Astar(Obiettivo obiettivo, Mappa *mappa);

private:
    View view; //a camera in the 2D scene
    Time times; //encapsulates a time value in a flexible way
    Clock clock;// a lightweight class for measuring time.
    bool eseguito=false;
public:
    void setEseguito(bool eseguito);

private:
    sf::Event event; //holds all the informations about a system event that just happened
    sf::RenderWindow window; //is the main class of the Graphics module
};

#endif //ELABORATO_N7_DISPLAY_H