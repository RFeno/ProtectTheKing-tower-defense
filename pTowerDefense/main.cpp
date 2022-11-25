#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "vGameBoard.h"
#include "Enemies.h"
#include "vEnnemy.h"
#include "TowerEarth.h"
#include <unistd.h>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));


    const int WIN_WIDTH = 1400;
    const int WIN_HEIGHT = 800;
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king");


//    vMainMenu mainMenu;
//    mainMenu.launchMenu(window);
    vGameBoard gameBoard(window);
    gameBoard.launchView();

    //test methods of modèle

//    Game game;
//
//    game.getMap()->addTower(new TowerEarth());
//
//    while(game.getNumeroOfWave() < 4)
//    {
//        cout << game.getMap()->strEnemies()  +"\n" << endl;
//        game.play()  ;
//        cout << game.getMap()->strEnemies() +"\n" << endl;
//    }



    exit(0);
}
