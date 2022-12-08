#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "vGameBoard.h"
#include "Enemies.h"
#include "vEnnemy.h"
#include "Gremlin.h"
#include <unistd.h>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(1400, 800), "Protect the king");

    vMainMenu mainMenu(window);
    mainMenu.launchMenu();

    exit(0);
}
