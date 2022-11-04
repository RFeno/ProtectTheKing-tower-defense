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

        cout<< typeOfEnemy << endl;
        //creation of ennemies randomly
        switch(typeOfEnemy)
        {
//            case 1:
//
//                KnightOfDeath knightofd;
//                this->mapOfGame.getEnemies().push_back(knightofd->clone());
//                break;
//
//            case 2:
//                Ogre ogre;
//                this->mapOfGame.getEnemies().push_back(ogre->clone());
//                break;
//            case 3:
//                Orc orc;
//                this->mapOfGame.getEnemies().push_back(orc->clone());
//                break;
//            case 4:
//                ShadowMonster shadowM;
//                this->mapOfGame.getEnemies().push_back(shadowM->clone());
//                break;
//            default:
//                cout << "error the create enemies for wave " << endl;
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


