#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "vGameBoard.h"

#include "State.h"
#include "Enemies.h"
#include "Ogre.h"
#include "Orc.h"

#include <unistd.h>

using namespace std;
using namespace sf;

int main()
{
//    srand(time(0));
//    const int WIN_WIDTH = 1400;
//    const int WIN_HEIGHT = 800;
//    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king");
//    vMainMenu mainMenu;
//    mainMenu.launchMenu(window);
//    vGameBoard gameBoard(window);
//    gameBoard.launchGame();

    //test methods of modèle
    Game game;
    game.launch();



    cout << game.getMap()->strEnemies() << endl;


    exit(0);
}
