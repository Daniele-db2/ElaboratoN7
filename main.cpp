#include <iostream>
#include <cmath>
#include "display.h"
#include "character.h"


int main() {
    srand((unsigned int)time(NULL));
    Personaggio p=Personaggio::crea();
    Obiettivo o;
    Schermo schermo;
    schermo.generaSchermo(o);
    return 0;
}
