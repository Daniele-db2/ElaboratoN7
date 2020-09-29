#include <iostream>
#include "Tile.h"

Tile::Tile() {
    char mappa1 = 'a';
    char mappa2 = 'b';
    char mappa3 = 'c';
    char Mappe[3] = {mappa1, mappa2, mappa3};
    for (int i = 0; i < 3; i++) {
        maps[i] = Mappe[i];
    }
}

Tile::~Tile() = default;