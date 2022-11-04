#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemies.h"
#include "Tower.h"
#include "TowerEarth.h"
#include "iostream"
#include "vMainMenu.h"
#include "Game.h"
#include "KnightOfDeath.h"

using namespace std;
using namespace sf;

int main()
{
//    const int WIN_WIDTH = 1400;
//    const int WIN_HEIGHT = 800;
//
//    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king - Welcome");
//
//    vMainMenu mainMenu;
//    mainMenu.launchMenu(window);

    //mainMenu.loadFont();

    //here the tests for the class of diagram will be realized
    Player playerOne("Saviour");

    TowerEarth towerEarthOne;

    //Enemies enemyOne(100);
    KnightOfDeath enemyTwo;


   //test attack of tower

    cout << "the health of enemy two: " << enemyTwo.getHealth() <<endl;

    cout << "the tower attack enemy two whith " <<towerEarthOne.getDamage() << "damage"<< endl;

    towerEarthOne.attackEnemy(enemyTwo);

    cout << "the health of enemy two: " << enemyTwo.getHealth() <<endl;

    //test tower improving
    cout << "*****************************************************" << endl;
    cout << "the level of tower:" <<towerEarthOne.getLevel() << endl;
    towerEarthOne.improveLevel();
    cout << "improve level of tower:" <<endl;
    cout << "the level of tower:" <<towerEarthOne.getLevel() << endl;
    towerEarthOne.improveLevel();
    cout << "improve level of tower:" <<endl;
    cout << "the level of tower:" <<towerEarthOne.getLevel() << endl;
    towerEarthOne.improveLevel();
    cout << "improve level of tower:" <<endl;
    cout << "the level of tower:" <<towerEarthOne.getLevel() << endl;
    towerEarthOne.improveLevel();
    cout << "improve level of tower:" <<endl;
    cout << "the level of tower:" <<towerEarthOne.getLevel() << endl;

    cout << "*****************************************************" << endl;
    cout << "achat de 4 tours différentes" <<endl;
    //cout << towerOne.toString() << endl;

    playerOne.setCoins(1500);
    playerOne.buyTower(earth);
    playerOne.buyTower(ice);
    playerOne.buyTower(sand);
    playerOne.buyTower(iron);

//    cout << "afficher les tours que le joueur one possède" <<endl;
//    for(Tower* t: playerOne.getTowers())
//    {
//        cout << t->toString() << endl;
//    }
//
//    for(list<Tower>::iterator it = playerOne.getTowers().begin(); it!=playerOne.getTowers().end() ; it++)
//    {
//        Tower t = *it;
//        cout << t.toString() << endl;
//    }


    Game game(playerOne.getName());
    game.startWave(15);




    return 0;
}
