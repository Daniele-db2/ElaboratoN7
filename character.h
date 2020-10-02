#ifndef ELABORATO_N7_CHARACTER_H
#define ELABORATO_N7_CHARACTER_H

#include <vector>
#include "Mappa.h"
#include </Users/giuliabellini/Desktop/ElaboratoN7_/SFML-2.5.1/include/SFML/Graphics.hpp>

using namespace sf;

using namespace std;

class Personaggio {
public:
    explicit Personaggio();
    Personaggio(int x, int y);
    int getX() const;
    int getY() const;
    void setPos(int x, int y);
    void setPos();
    int getIndex() const;
    const vector<Vector2f> &getCoordinate() const;
    void DisegnaPersonaggio(RenderWindow &window);
    static Personaggio& crea();
    static Personaggio& crea(int x, int y);
    void setCoordinate(int x, int y);

private:
    int x;
    int y;
    vector<Vector2f> coordinate;
    Sprite sprite;
    Texture texture;
    int index=0;
};

#endif //ELABORATO_N7_CHARACTER_H
