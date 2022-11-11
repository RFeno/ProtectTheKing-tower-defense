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

#include <vector>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));
//    const int WIN_WIDTH = 1400;
//    const int WIN_HEIGHT = 800;
//
//    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king - Welcome");
//
//    vMainMenu mainMenu;
//    mainMenu.launchMenu(window);

    //mainMenu.loadFont();

    Game game("PlayerName");

    game.startWave(15);

    cout << game.getMap()->strEnemies() << endl;

    cout << game.getMap()->getEnemies().size() << endl;

    return 0;
}
