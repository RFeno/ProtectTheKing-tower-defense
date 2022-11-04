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
Game::Game(string nameOfPlayer)
{
    this->player = new Player(nameOfPlayer);
    this->king = new King();
    this->mapOfGame = new Map();
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
void Game::startWave(int numberOfEnemies)
{
    for(int i = 1; i<= numberOfEnemies;i++)
    {
        int typeOfEnemy = rand()%4 +1;

        //creation of ennemies randomly
        switch(typeOfEnemy)
        {

            case 1:
                {
                    cout << to_string(mapOfGame->getEnemies().size()) << endl;
                    //ask if we need to delete if we clone
                    KnightOfDeath* knightofd = new KnightOfDeath;
                    mapOfGame->getEnemies().push_back(knightofd->clone());

                    //delete knightofd;
                    break;
                }
            case 2:
                {
                    cout << to_string(mapOfGame->getEnemies().size()) << endl;
                    Ogre* ogre = new Ogre;
                    this->mapOfGame->getEnemies().push_back(ogre->clone());
                    delete ogre;
                    break;
                }
            case 3:
                {
                    cout << to_string(mapOfGame->getEnemies().size()) << endl;
                    Orc* orc = new Orc;
                    mapOfGame->getEnemies().push_back(orc->clone());
                    delete orc;
                    break;
                }
            case 4:
                {
                    cout << to_string(mapOfGame->getEnemies().size()) << endl;
                    //ShadowMonster* shadowM = ;
                    mapOfGame->getEnemies().push_back(new ShadowMonster);
                    //delete shadowM;
                    break;
                }

            default:
                cout << "error the create enemies for wave " << endl;
        }
    }
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


