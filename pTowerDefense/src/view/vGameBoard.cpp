#include "vGameBoard.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

using namespace std;

//Texture mapTexture;
//Texture pauseTexture;
////Texture musiqueOnTexture;
//Texture acideCloudTexture;
//Texture lightningTexture;
//Texture fireTexture;
//
//Sprite mapSprte;
//Sprite pauseSprote;
////Sprite musiqueOnSprite;
//Sprite acideCloudSprite;
//Sprite lightningSprite;
//Sprite fireSprite;


vGameBoard::vGameBoard()
{
    //ctor
}

vGameBoard::~vGameBoard()
{
    //dtor
}

vGameBoard::vGameBoard(const vGameBoard& other)
{
    //copy ctor
}

vGameBoard& vGameBoard::operator=(const vGameBoard& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void vGameBoard::launchView(RenderWindow& window)
{

    //vsynch activation
    window.setVerticalSyncEnabled(true);
    // limit the window to 60 images per second
    window.setFramerateLimit(60);

    if(verifyImage())
    {
        loadSprite();
         while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                InputHandler(event, window);
            }

            window.clear();
            drawEntities(window);
            window.display();
        }
    }

    else
        cout << "error" <<endl;
}

/*to manage the events */
void vGameBoard::InputHandler(Event event, RenderWindow &window)
{
    // close the window
//    if (event.type == Event::Closed)
//    {
//        window.close();
//    }
//
//    // detect mouse click
//    if (event.type == Event::MouseButtonPressed)
//    {
//        if (event.mouseButton.button == Mouse::Left)
//        {
//            cout << "Play :" <<isSpriteClicked(playSprite, window) << endl;
//            cout << "Settings :" <<isSpriteClicked(settingsSprite, window) << endl;
//            cout << "Musique :" <<isSpriteClicked(musiqueOnSprite, window) << endl;
//
//            if(isSpriteClicked(playSprite, window) == 1)
//            {
//                window.close();
//                RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Protect the king - Game");
////                vGame game;
////                game.launchGame(window);
//            }
//
//        }
//        if (event.mouseButton.button == Mouse::Right)
//        {
//              cout << "right click"<< endl;
//        }
//    }

}

/* to load the sprites */
void vGameBoard::loadSprite()
{
//adding texture to sprite
//    settingsSprite.setTexture(settingsTexture);
//    playSprite.setTexture(playTexture);
//    mapSprte.setTexture(mapTexture);
//    logoSprite.setTexture(logoTexture);
//
//    //set positions
//    playSprite.setPosition(sf::Vector2f(600, 600));
//    settingsSprite.setPosition(sf::Vector2f(1230, 15));
//    logoSprite.setPosition(sf::Vector2f(200, -30));
//    musiqueOnSprite.setPosition(Vector2f(0, 15));
//    musiqueOnSprite.setPosition(Vector2f(0, 15));
//
//    //change widht
//    playSprite.setScale(0.5f, 0.5f);
//    logoSprite.setScale(1.0f, 1.0f);
}

/* to verify if all images is accessible and charge in the texture */
bool vGameBoard::verifyImage()
{
    //verify load images
//    if(!bgTexture.loadFromFile("res/images/menu/bg.png"))
//    {
//        cout << "ERROR chargement texture" << endl;
//        return false;
//    }
//
//    if(!musiqueOnTexture.loadFromFile("res/images/menu/button_music.png"))
//    {
//        cout << "ERROR chargement texture" << endl;
//        return false;
//    }
//
//    if(!musiqueOffTexture.loadFromFile("res/images/menu/button_music_off.png"))
//    {
//        cout << "ERROR chargement texture" << endl;
//        return false;
//    }
//
//    if(!settingsTexture.loadFromFile("res/images/menu/button_settings.png"))
//    {
//        cout << "ERROR chargement texture" << endl;
//        return false;
//    }
//
//
//    if (!playTexture.loadFromFile("res/images/menu/button_play.png"))
//    {
//         cout << "ERROR chargement texture" << endl;
//         return false;
//    }
//
//    if (!logoTexture.loadFromFile("res/images/menu/logo.png"))
//    {
//         cout << "ERROR chargement texture" << endl;
//         return false;
//    }

    return true;
}
/* to draw the entitties in the window */
void vGameBoard::drawEntities(RenderWindow& window)
{
    //display elemeents
    //window.draw(bgSprite);
//    window.draw(musiqueOnSprite);
//    window.draw(settingsSprite);
//    window.draw(logoSprite);
//    window.draw(playSprite);
}

//fonction for actionEvent on Buttons Sprite
bool vGameBoard::isSpriteClicked (Sprite &spr, RenderWindow &window )
{
    //take the position of the mouse
    Vector2i mousePos = Mouse::getPosition(window);

    //condition if it is in the sprite
	if(mousePos.x > spr.getPosition().x
		&& mousePos.x < spr.getPosition().x + spr.getTexture()->getSize().x
		&& mousePos.y > spr.getPosition().y && mousePos.y < spr.getPosition().y + spr.getTexture()->getSize().y
		&& Mouse::isButtonPressed(Mouse::Left)
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}
