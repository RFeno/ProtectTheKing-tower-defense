#include <SFML/Graphics.hpp>
#include "iostream"
#include "vMainMenu.h"
#include "Game.h"
#include "vGameBoard.h"
#include <ctime>
#include <chrono>

#include <unistd.h>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));
    const int WIN_WIDTH = 1400;
    const int WIN_HEIGHT = 800;
//
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king - Welcome");
//    vMainMenu mainMenu;
//    mainMenu.launchMenu(window);

    vGameBoard gameBoard(window);
    gameBoard.launchView();

    //gestion du temps
//    for(int i=0;i<5;i++)
//    {
//        cout << "hello" << endl;
//        sleep(1);
//    }

//    for(auto runUntil = chrono::system_clock::now() + chrono::seconds(2);
//            chrono::system_clock::now() < runUntil;)
//        {
//            // Do something
//            cout << "Hi !" << endl;
//        }


//


    return 0;
}
