#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemies.h"
#include "Tower.h"
#include "TowerEarth.h"
#include "iostream"
#include "vMainMenu.h"
#include "Game.h"
#include "KnightOfDeath.h"
#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"

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

    Game game("Saviour");

    game.startWave(15);

    cout << to_string(game.getMap()->getEnemies().size()) <<endl;


    cout << game.getMap()->strEnemies() << endl;

    return 0;
}
