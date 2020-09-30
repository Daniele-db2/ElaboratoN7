#include "googletest/googletest/include/gtest/gtest.h"
#include "../Mappa.h"
#include "../character.h"
#include "../Goal.h"
#include "../display.h"


TEST(DimensioneMappa,Mappatest0 ) {
Mappa map0 = Mappa::crea(0);
ASSERT_EQ(map0.getRows(),28) << "Map reading problem: height not calculated correctly.";
ASSERT_EQ(map0.getColumns(),28) << "Map reading problem: width not calculated correctly.";
std::cout<<"Dimensioni mappa calcolate correttamente"<<endl;
}


TEST(DimensioneMappa, Mappatest1){
Mappa map1 = Mappa::crea(0);
ASSERT_EQ(map1.getRows(),16) << "Small map reading problem: height not calculated correctly.";
ASSERT_EQ(map1.getColumns(),16) << "Small map reading problem: width not calculated correctly.";
std::cout<<"Dimensioni mappa calcolate correttamente"<<endl;
}

TEST(PosizionePersonaggio,check) {
Mappa map2 = Mappa::crea(0);
Personaggio pers = Personaggio::crea();
int x = (rand()% (map2.getColumns()/2)+5);
int y = (rand() % (map2.getRows()/2)+5);
Obiettivo obiettivo = Obiettivo(x, y);
int X = pers.getX();
int Y = pers.getY();
map2.tiles[X-1][Y-1] = 204;
map2.tiles[X-1][Y] = 204;
map2.tiles[X-1][Y+1] = 204;
map2.tiles[X][Y-1] = 204;
map2.tiles[X][Y+1] = 204;
map2.tiles[X+1][Y-1] = 204;
map2.tiles[X+1][Y] = 204;
map2.tiles[X+1][Y+1] = 204;
Schermo schermo;
string g = schermo.Astar(obiettivo);
ASSERT_EQ(g, "Search terminated. Did not find goal state") << "Posizione finale raggiunta correttamente";
std::cout<<"\nObiettivo non raggiunto"<<endl;
}

