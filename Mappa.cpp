#include "Mappa.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <istream>

#define TILE 32

using namespace std;
using namespace sf;

Mappa &Mappa::crea(int z) {
    static Mappa mappa(z);
    return mappa;
}

Mappa::Mappa(int z) {
    string s;
    stringstream ss;
    if (z == 0) {
        cout<<"scegli mappa "<<endl;
        cin>>s;
        ss << s;
        ss >> s;

        fstream mapTextFile;
        mapTextFile.open("./Maps/" + s);
        cout << "ALGORITMO A* CON UTILIZZO DI MAPPA: " << endl;
        cout << s << endl;

        int i = 0;
        string line;
        vector<int> lineTiles;

        while (getline(mapTextFile, line)) {
            istringstream iss(line);
            while (iss >> i) {
                lineTiles.push_back(i);
            }
            tiles.push_back(lineTiles);//vettore di vettori
            lineTiles.clear();
        }
        mapTextFile.close();
        findDimension();
    }
    else{
        int array[3] = {};
        for (int k = 0; k < 3;k++)
            array[k] = tile.maps[k];
        char Nomemappa = char(array[rand()%3]);
        ss << Nomemappa;
        ss >> s;

        fstream mapTextFile;
        mapTextFile.open("./Maps/" + s);
        cout << "ALGORITMO A* CON UTILIZZO DI MAPPA: " << endl;
        cout << s << endl;

        int i = 0;
        string line;
        vector<int> lineTiles;


        while (getline(mapTextFile, line)) {
            istringstream iss(line);
            while (iss >> i) {
                lineTiles.push_back(i);
            }
            tiles.push_back(lineTiles);//vettore di vettori
            lineTiles.clear();
        }
        mapTextFile.close();
        findDimension();
    }
}

void Mappa::findDimension() {
    rows=tiles[0].size();
    columns=tiles[0].size();
}

int Mappa::getRows() const {
    return rows;
}

int Mappa::getColumns() const  {
    return columns;
}

int Mappa::GetMap( int x, int y) {
    if( x < 0 || x >= rows|| y < 0 || y >= columns) {
        return 9;
    }
    return tiles[x][y];
}

bool Mappa::load() {
    if (!tex.loadFromFile("/Users/giuliabellini/Desktop/tileset.png"))// load the map tileset texture
        return false;
    m_vertices.setPrimitiveType(sf::Quads); // resize the vertex array to fit the tile size
    m_vertices.resize(rows * columns * 4);// populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < columns; j++) {
            int tileNumber = tiles[i][j];// get the current tile number

            int tu = tileNumber % (tex.getSize().x / TILE); // getSize() return the size (in Pixels) of the texture.

            int tv = tileNumber / (tex.getSize().x / TILE);// find its position in the tileset texture

            sf::Vertex *quad = &m_vertices[(j + i * columns) * 4];// get a pointer to the current tile's quad

            quad[0].position = sf::Vector2f(j * TILE, i * TILE);

            quad[1].position = sf::Vector2f((j + 1) * TILE, i * TILE);

            quad[2].position = sf::Vector2f((j + 1) * TILE, (i + 1) * TILE);

            quad[3].position = sf::Vector2f(j * TILE, (i + 1) * TILE);

            quad[0].texCoords = sf::Vector2f(tu * TILE, tv * TILE);// define its 4 texture coordinates

            quad[1].texCoords = sf::Vector2f((tu + 1) * TILE, tv * TILE);

            quad[2].texCoords = sf::Vector2f((tu + 1) * TILE, (tv + 1) * TILE);

            quad[3].texCoords = sf::Vector2f(tu * TILE, (tv + 1) * TILE);

        }
    }

    states.texture=&tex;
    return true;
}

int Mappa::getTiles(int x, int y) const {
    return tiles[x][y];
}

void Mappa::DisegnaMappa(RenderWindow &window) {
    window.draw(m_vertices, states);
}

