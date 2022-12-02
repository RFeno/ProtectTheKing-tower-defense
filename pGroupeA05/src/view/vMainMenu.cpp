#include "vMainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "vGame.h"
#include "vGameBoard.h"
using namespace sf;

using namespace std;

vMainMenu::vMainMenu(RenderWindow& window)
{
    //ctor
    windowFromMain=&window;
}

vMainMenu::~vMainMenu()
{
    //dtor
}

/**launch menuView */
void vMainMenu::launchMenu()
{
    //vsynch activation
    windowFromMain->setVerticalSyncEnabled(true);
    // limit the window to 60 images per second
    windowFromMain->setFramerateLimit(60);

    if(verifyImage())
    {
        loadSprite();
         while (windowFromMain->isOpen())
        {
            Event event;
            while (windowFromMain->pollEvent(event))
            {
                InputHandler(event);
            }
            windowFromMain->clear();
            drawEntities();
            windowFromMain->display();
        }
    }

}

/**to manage the events */
void vMainMenu::InputHandler(Event event)
{
    // close the window
    if (event.type == Event::Closed)
    {
        windowFromMain->close();
    }

    // detect mouse click
    if (event.type == Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == Mouse::Left)
        {
            if(isSpriteClicked(playSprite))
            {
                vGameBoard game(*windowFromMain);
                game.launchView();
            }
        }
    }
}

/** to load the sprites */
void vMainMenu::loadSprite()
{
    //adding texture to sprite
    musiqueOnSprite.setTexture(musiqueOnTexture);
    musiqueOffSprite.setTexture(musiqueOffTexture);
    settingsSprite.setTexture(settingsTexture);
    playSprite.setTexture(playTexture);
    bgSprite.setTexture(bgTexture);
    logoSprite.setTexture(logoTexture);

    //set positions
    playSprite.setPosition(sf::Vector2f(600, 600));
    settingsSprite.setPosition(sf::Vector2f(1230, 15));
    logoSprite.setPosition(sf::Vector2f(200, -30));
    musiqueOnSprite.setPosition(Vector2f(0, 15));
    musiqueOnSprite.setPosition(Vector2f(0, 15));

    //change widht
    playSprite.setScale(0.5f, 0.5f);
    logoSprite.setScale(1.0f, 1.0f);
}

/** to verify if all images is accessible and charge in the texture */
bool vMainMenu::verifyImage()
{
    //verify load images
    if(!bgTexture.loadFromFile("res/images/menu/bg.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!musiqueOnTexture.loadFromFile("res/images/menu/button_music.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!musiqueOffTexture.loadFromFile("res/images/menu/button_music_off.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if(!settingsTexture.loadFromFile("res/images/menu/button_settings.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }


    if (!playTexture.loadFromFile("res/images/menu/button_play.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    if (!logoTexture.loadFromFile("res/images/menu/logo.png"))
    {
        cout << "ERROR chargement texture" << endl;
        return false;
    }

    return true;
}

/** to draw the entitties in the window */
void vMainMenu::drawEntities()
{
    //display elemeents
    //windowFromMain->draw(bgSprite);
    windowFromMain->draw(musiqueOnSprite);
    windowFromMain->draw(settingsSprite);
    windowFromMain->draw(logoSprite);
    windowFromMain->draw(playSprite);
}

/**Return if the sprite is clicked */
bool vMainMenu::isSpriteClicked (Sprite &spr )
{
    //take the position of the mouse
    Vector2i mousePos = Mouse::getPosition(*windowFromMain);

    //condition if it is in the sprite
	if(mousePos.x > spr.getPosition().x && mousePos.x < spr.getPosition().x + spr.getTexture()->getSize().x
		&& mousePos.y > spr.getPosition().y && mousePos.y < spr.getPosition().y + spr.getTexture()->getSize().y
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}

