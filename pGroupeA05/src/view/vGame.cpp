#include "vGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

using namespace std;

vGame::vGame()
{
    //ctor
}

vGame::~vGame()
{
    //dtor
}

void vGame::launchGame(RenderWindow& window)
{

    //vsynch activation
    //window.setVerticalSyncEnabled(true);

    while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                InputHandler(event, window);

            }

            window.clear();
            window.display();
        }
}

void vGame::InputHandler(Event event, RenderWindow &window)
{
    // close the window
    if (event.type == Event::Closed)
    {
        window.close();
    }

}
