#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "vGameBoard.h"
#include "Enemies.h"
#include "vEnnemy.h"
#include "Gremlin.h"
#include <unistd.h>

#include <vGameManager.h>

using namespace std;
using namespace sf;

int main()
{

    /*Gremlin grem;
    grem.setX(200.5);
    grem.setHealth(5000);
    grem.setWalkingSpeed(500);
    grem.setY(600);

    Gremlin salut;

    cout << salut.getInformations() << endl;

    salut=grem;

    cout << salut.getInformations() << endl;*/

    srand(time(0));

    RenderWindow window(VideoMode(1400, 800), "Protect the king");

    vMainMenu mainMenu(window);
    mainMenu.launchMenu();

//    vGameManager gameMan;
//    gameMan.launchGame();

//    vGameBoard gameBoard(window);
//    gameBoard.launchView();

    //test methods of modèle

    /*Game game;

    game.getMap()->addTower(-40,200,earth);
    game.createWave();

    for(int i=0;i<(int)game.getMap()->getEnemies().size();i++)
    {
        game.getMap()->getEnemies()[i]->setSpawn(true);
    }

    for(int i=0;i<(int)game.getMap()->getEnemies().size();i++)
    {
        game.getMap()->getEnemies()[i]->setSpawn(true);

        cout << game.getMap()->strEnemies()  +"\n" << endl;
        game.ennemiesWalk();
        game.towerAttack();
        game.ennemiesAttack();
    }*/

    exit(0);
}
