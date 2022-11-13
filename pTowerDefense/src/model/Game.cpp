#include "Game.h"
#include "Player.h"
#include "King.h"
#include "Map.h"
#include <string>
#include <iostream>
#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"

using namespace std;

//ctor
Game::Game()
{
    this->player = new Player();
    this->king = new King();
    this->mapOfGame = new Map();
    numberOfWave =1;
    numberOfEnemies = 5;
}
//dtor
Game::~Game()
{
    delete player;
    delete king;
    delete mapOfGame;
}

Game::Game(const Game& other)
{
    //copy ctor
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
/* launch the wave, generat*/
void Game::createWave(int numberOfEnemies)
{
    KnightOfDeath* knightofd = new KnightOfDeath();
    Orc* orc = new Orc();
    Ogre* ogre = new Ogre();
    ShadowMonster* shadowM = new ShadowMonster();

    for(int i = 1; i<= numberOfEnemies;i++)
    {
        int typeOfEnemy = rand()%4 +1;

        //creation of ennemies randomly
        //the clone is created in the method addEnemy

        switch(typeOfEnemy)
        {
            case 1:
                {
                    //mapOfGame->getEnemies().push_back(knightofd.clone());
                    mapOfGame->addEnemy(knightofd);
                    break;
                }
            case 2:
                {
                    mapOfGame->addEnemy(ogre);
                    //mapOfGame->getEnemies().push_back(ogre.clone());
                    break;
                }
            case 3:
                {
                    mapOfGame->addEnemy(orc);
                    //mapOfGame->getEnemies().push_back(orc.clone());
                    break;
                }
            case 4:
                {
                    mapOfGame->addEnemy(shadowM);
                    //mapOfGame->getEnemies().push_back(shadowM.clone());
                    break;
                }

            default:
                cout << "error the create enemies for wave " << endl;
        }
    }
    delete knightofd;
    delete ogre;
    delete orc;
    delete shadowM;
}
/* is launch after all enemies are dead */
bool Game::endWave()
{
    return false;
}
/*cuts the game when the player has lost (when the king is dead) */
bool Game::gameOver()
{
    return false;
}


