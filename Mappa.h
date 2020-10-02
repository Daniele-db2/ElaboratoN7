

#ifndef ELABORATO_N7_MAPPA_H
#define ELABORATO_N7_MAPPA_H

#include <string>
#include <vector>
#include <fstream>
#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics.hpp>
#include "Tile.h"


using namespace sf;

using namespace std;

class Mappa {
private:
    Texture tex;
    VertexArray m_vertices;
    RenderStates states;
    int rows=0;
    int columns=0;
    vector<int> type;
    //static Mappa* map;
    explicit Mappa(int z);
public:
    Tile tile;
    static Mappa* crea(int z);
    int getColumns() const;
    int getRows() const ;
    int GetMap(int x, int y);
    void findDimension();
    bool load();
    void DisegnaMappa(RenderWindow &window);
    int getTiles(int x, int y) const;
    vector <vector<int> > tiles;
};

#endif //ELABORATO_N7_MAPPA_H
