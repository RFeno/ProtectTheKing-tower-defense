#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "vGameBoard.h"
#include "Enemies.h"
#include "vEnnemy.h"
#include "TowerEarth.h"
#include <unistd.h>

#include <vGameManager.h>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(1400, 800), "Protect the king");

    vMainMenu mainMenu(window);
    mainMenu.launchMenu();

//    vGameManager gameMan;
//    gameMan.launchGame();

//    vGameBoard gameBoard(window);
//    gameBoard.launchView();

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


    //exit(0);
}
