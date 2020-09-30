#ifndef ELABORATO_N7_MAPSEARCHNODE_H
#define ELABORATO_N7_MAPSEARCHNODE_H

#include "stlastar.h"
#include "Mappa.h"


class MapSearchNode
{
public:
    int x;	 // the (x,y) positions of the node
    int y;
    Mappa *map;

    MapSearchNode() { x = y = 0;}

    MapSearchNode( int px, int py ) { x=px; y=py;  }



    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    float GetCost( MapSearchNode &successor );
    bool IsSameState( MapSearchNode &rhs );



    void PrintNodeInfo(Mappa *mappa);


};
#endif //ELABORATO_N7_MAPSEARCHNODE_H
