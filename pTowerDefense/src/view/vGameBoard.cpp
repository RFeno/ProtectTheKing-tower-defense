#include "vGameBoard.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>

#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"

using namespace sf;
using namespace std;

vGameBoard::vGameBoard(RenderWindow& window)
{
    this->windowFromMain = &window;
    //ctor
    game.createWave(8);
    for(int i=0; i< (int)game.getMap()->getEnemies().size(); i++)
    {
        enemiesSprite.push_back(new Sprite());
    }

    cout << game.getMap()->getEnemies().size() << endl;

    cout << game.getMap()->strEnemies() << endl;

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

void vGameBoard::launchView()
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
                InputHandler(event, windowFromMain);
            }
            animationEnemyWalk();
            enemiesSpawn();
            windowFromMain->clear();
            drawEntities(*windowFromMain);
            windowFromMain->display();
        }
    }
    else
        cout << "error" <<endl;


}

/*to manage the events */
void vGameBoard::InputHandler(Event event, RenderWindow *window)
{
    // close the window
    if (event.type == Event::Closed)
    {
        window->close();
    }
    // detect mouse click
    if (event.type == Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == Mouse::Left)
        {
            animationEnemyWalk();
        }
        if (event.mouseButton.button == Mouse::Right)
        {
              cout << "right click"<< endl;
        }
    }

}

/* to load the sprites */
void vGameBoard::loadSprite()
{
    //adding texture to sprite
    mapSprite.setTexture(mapTexture);

    // un sprite = 377 , 404
    // Les 2 premiers argument = position d'origine
    // Les 2 d'après, taille d'un sprite
    // Donc si tu veux prendre le deuxième sprite -> + 377 au premier argument et ansi de suite

    for(size_t i=0;i<enemiesSprite.size();i++)
    {


        if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
        {
            enemiesSprite[i]->setTexture(ogreTexture);
            enemiesSprite[i]->setTextureRect(IntRect(0,0,OGRE_WIDTH,OGRE_HEIGHT));
            enemiesSprite[i]->setPosition(Vector2f(i*100, 535));
            enemiesSprite[i]->setScale(0.28,0.28f);
        }

         if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
        {
            enemiesSprite[i]->setTexture(orcTexture);
            enemiesSprite[i]->setTextureRect(IntRect(0,0,ORC_WIDTH,ORC_HEIGHT));
            enemiesSprite[i]->setPosition(Vector2f(i*100, 545));
            enemiesSprite[i]->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
        {
            enemiesSprite[i]->setTexture(shadowMonsterTexture);
            enemiesSprite[i]->setTextureRect(IntRect(0,0,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
            enemiesSprite[i]->setPosition(Vector2f(i*100, 553));
            enemiesSprite[i]->setScale(0.28f,0.28f);
        }

        if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
        {
            enemiesSprite[i]->setTexture(knightOfDeathTexture);
            enemiesSprite[i]->setTextureRect(IntRect(0,0,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
            enemiesSprite[i]->setPosition(Vector2f(i*100, 518));
            enemiesSprite[i]->setScale(0.28f,0.28f);
        }

         if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
        {
            enemiesSprite[i]->setTexture(gremlinTexture);
            enemiesSprite[i]->setTextureRect(IntRect(0,0,GREMLIN_WIDTH,GREMLIN_HEIGHT));
            enemiesSprite[i]->setPosition(Vector2f(i*100, 575));
            enemiesSprite[i]->setScale(0.28f,0.28f);
        }
    }

    mapSprite.setScale(0.73f,0.75f);

}

/* to verify if all images is accessible and charge in the texture */
bool vGameBoard::verifyImage()
{
    //verify load images
    if (!orcTexture.loadFromFile("res/images/sprites/2/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!gremlinTexture.loadFromFile("res/images/sprites/3/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!shadowMonsterTexture.loadFromFile("res/images/sprites/5/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!knightOfDeathTexture.loadFromFile("res/images/sprites/9/spritesheet_WALK.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!mapTexture.loadFromFile("res/images/gameBoard/map.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    if (!ogreTexture.loadFromFile("res/images/sprites/1/1_enemies_1_WALK_spritesheet.png"))
    {
         cout << "ERROR chargement texture" << endl;
         return false;
    }

    return true;
}
/* to draw the entitties in the window */
bool vGameBoard::drawEntities(RenderWindow& window)
{
    //display elemeents
    window.draw(mapSprite);

    for(size_t i=0;i<enemiesSprite.size();i++)
    {
        window.draw(*enemiesSprite[i]);
    }

    return true;

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

void vGameBoard::animationEnemyWalk()
{
    if(animClock.getElapsedTime().asSeconds() > 0.1f)
    {
         for(size_t i=0;i<enemiesSprite.size();i++)
         {

            if(dynamic_cast<Ogre*>(game.getMap()->getEnemies()[i]))
            {
                enemiesSprite[i]->setTextureRect(IntRect(x_Ogre*OGRE_WIDTH,y_Ogre*OGRE_HEIGHT,OGRE_WIDTH,OGRE_HEIGHT));
            }

             if(dynamic_cast<Orc*>(game.getMap()->getEnemies()[i]))
            {
                enemiesSprite[i]->setTextureRect(IntRect(x_Orc*ORC_WIDTH,y_Orc*ORC_HEIGHT,ORC_WIDTH,ORC_HEIGHT));
            }

            if(dynamic_cast<ShadowMonster*>(game.getMap()->getEnemies()[i]))
            {
                enemiesSprite[i]->setTextureRect(IntRect(x_shadowMonster*SHADOWMONSTER_WIDTH,y_shadowMonster*SHADOWMONSTER_HEIGHT,SHADOWMONSTER_WIDTH,SHADOWMONSTER_HEIGHT));
            }

            if(dynamic_cast<KnightOfDeath*>(game.getMap()->getEnemies()[i]))
            {
                enemiesSprite[i]->setTextureRect(IntRect(x_knight*KNIGHTOFDEATH_WIDTH,y_knight*KNIGHTOFDEATH_HEIGHT,KNIGHTOFDEATH_WIDTH,KNIGHTOFDEATH_HEIGHT));
            }

            if(dynamic_cast<Gremlin*>(game.getMap()->getEnemies()[i]))
            {
                enemiesSprite[i]->setTextureRect(IntRect(x_gremlin*GREMLIN_WIDTH,y_gremlin*GREMLIN_HEIGHT,GREMLIN_WIDTH,GREMLIN_HEIGHT));
            }


         }

        if(x_Ogre*OGRE_WIDTH >= (int)ogreTexture.getSize().x - OGRE_HEIGHT)
        {
            x_Ogre = 0;
        }
        else
        {
            x_Ogre++;
        }



        if(x_shadowMonster*SHADOWMONSTER_WIDTH >= (int)shadowMonsterTexture.getSize().x - SHADOWMONSTER_HEIGHT)
        {
            x_shadowMonster = 0;
        }
        else
        {
            x_shadowMonster++;
        }



        if(x_Orc*ORC_WIDTH >= (int)orcTexture.getSize().x - ORC_HEIGHT)
        {
            x_Orc = 0;
        }
        else
        {
            x_Orc++;
        }

        if(x_gremlin*GREMLIN_WIDTH >= (int)gremlinTexture.getSize().x - GREMLIN_HEIGHT)
        {
            x_gremlin = 0;
        }
        else
        {
            x_gremlin++;
        }

        if(x_knight*KNIGHTOFDEATH_WIDTH >= (int)knightOfDeathTexture.getSize().x - KNIGHTOFDEATH_HEIGHT)
        {
            x_knight = 0;
        }
        else
        {
            x_knight++;
        }

        /*for(size_t i=0;i<enemiesSprite.size();i++)
        {
           enemiesSprite[i]->move(WALK_SPEED,0);
        }*/

        animClock.restart();

        //for the deplacement



    }
}

void vGameBoard::animationEnemyWalk2(Sprite *enemy)
{
    //enemy.setTextureRect(IntRect(x*SPRITE_WIDTH,y*SPRITE_HEIGHT,SPRITE_WIDTH,SPRITE_HEIGHT));

//    if(animClock.getElapsedTime().asSeconds() > 0.1f)
//    {
//        /*at the end of sheet sprite */
//        if(x*SPRITE_WIDTH >= (int)enemy->getTexture()->getSize().x - SPRITE_WIDTH)
//        {
//            x = 0;
//        }
//        else
//        {
//            x++;
//        }
//        animClock.restart();
//    }

    //enemy->setPosition(Vector2f(enemy->getPosition().x + WALK_SPEED, 535));
}

void vGameBoard::enemiesSpawn()
{
   /* int idSpawn = 0;

    if(spawnClock.getElapsedTime().asSeconds() > 2 && idSpawn < (int)enemiesSprite.size())
    {
        animationEnemyWalk2(enemiesSprite[idSpawn]);
        idSpawn++;
        spawnClock.restart();
        cout<<"test 2"<<endl;
    }*/
}
