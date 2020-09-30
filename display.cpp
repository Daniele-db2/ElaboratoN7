#include "display.h"
#include "Mappa.h"
#include "character.h"
#include "Goal.h"
#include "stlastar.h"
#include "MapSearchNode.h"
#include <ctime>


#define TILE 32



Schermo::~Schermo() = default;


Schermo::Schermo(Mappa *mappa) {
    mappa->load();
    view.setSize(mappa->getRows()*TILE, mappa->getColumns()*TILE);
    view.setCenter(mappa->getRows()*TILE/2, mappa->getColumns()*TILE/2);
    sf::WindowHandle handle = window.getSystemHandle(); //Get the OS-specific handle of the window
    window.create(VideoMode(800,600),"A* ALGORITHM");
    window.setFramerateLimit(60); //Limit the framerate to a maximum fixed frequenc,Parameters: Framerate limit, in frames per seconds
}

string Schermo::generaSchermo(Obiettivo obiettivo, Mappa *mappa) {
    string fstring;

    while (window.isOpen()) {
        while (window.pollEvent(event)) { //Pop the event on top of the event queue, if any, and return it.
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.setView(view); //Change the current active view
        window.setActive(); //Activate or deactivate the window as the current target for OpenGL rendering.
        window.clear();
        mappa->DisegnaMappa(window);
        obiettivo.drawPersonaggio(window);

        if (!eseguito)
            fstring = Astar(obiettivo, mappa);
        this->setEseguito(true);

        times=clock.getElapsedTime(); //returns the time elapsed since the last call to restart()
        if(times.asSeconds()>1){
            Personaggio::crea(mappa).setPos();
            clock.restart(); //puts the time counter back to zero
        }
        Personaggio::crea(mappa).DisegnaPersonaggio(window);
        window.display();//rendering has been done for the current frame, in order to show it on screen
    }
    return fstring;
}

string Schermo::Astar( Obiettivo obiettivo,Mappa *mappa) {
    string goal;

    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchCount = 0;
    const unsigned int NumSearches = 1;
    while (SearchCount < NumSearches) {

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = Personaggio::crea(mappa).getX();
        nodeStart.y = Personaggio::crea(mappa).getY();
        cout << "Punto di partenza (" << nodeStart.x << "," << nodeStart.y << ")" << endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = obiettivo.getX();
        nodeEnd.y = obiettivo.getY();
        cout << "Punto di arrivo (" << nodeEnd.x << "," << nodeEnd.y << ")" << endl;

        // Set Start and goal states
        astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);
        unsigned int SearchState;
        unsigned int SearchSteps = 0;
        do {
            SearchState = astarsearch.SearchStep();
            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
#endif

        } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);
        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
            cout << "Search found goal state\n";
            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif

            int steps = 0;
            node->PrintNodeInfo(mappa);
            for (;;) {
                node = astarsearch.GetSolutionNext();
                if (!node) {
                    break;
                }
                node->PrintNodeInfo(mappa);
                steps++;
            };
            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();
            goal = "OBIETTIVO RAGGIUNTO";
        } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
            goal = "Search terminated. Did not find goal state";
        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n"<<endl;
        SearchCount++;
        astarsearch.EnsureMemoryFreed();
    }
    return goal;
}

void Schermo::setEseguito(bool eseguito) {
    Schermo::eseguito = eseguito;
}

