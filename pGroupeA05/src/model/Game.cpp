/** MODEL */
#include "Game.h"
#include "Player.h"
#include "King.h"
#include "Map.h"

/** STATES */
#include "State.h"
#include "StateDie.h"

#include <string>
#include <iostream>



using namespace std;

//ctor
Game::Game()
{
    this->player = new Player();
    this->mapOfGame = new Map();
}
//dtor
Game::~Game()
{
    delete player;
    delete mapOfGame;
}

Game::Game(const Game& other): player(other.player), mapOfGame(other.mapOfGame)
{
    //copy ctor
}

Game& Game::operator=(const Game& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    if(player!=nullptr)
    {
        delete player;
    }

    if(mapOfGame!=nullptr)
    {
        delete mapOfGame;
    }

    this->player=rhs.player;
    this->mapOfGame=rhs.mapOfGame;

    //assignment operator
    return *this;
}

/** launch the wave, generate enemies*/
void Game::createWave()
{
    numeroOfWave++;

    for(int i = 1; i<= numberOfEnemies;i++)
    {
        int typeOfEnemy = rand()%5 +1;

        ///creation of ennemies randomly
        switch(typeOfEnemy)
        {
            case 1:
            {
                mapOfGame->addEnemy(knightOfDeathValue);
                break;
            }
            case 2:
            {
                mapOfGame->addEnemy(ogreValue);
                break;
            }
            case 3:
            {
                mapOfGame->addEnemy(orcValue);
                break;
            }
            case 4:
            {
                mapOfGame->addEnemy(shadowMonsterValue);
                break;
            }
            case 5:
            {
                mapOfGame->addEnemy(gremlinValue);
                break;
            }
        }
    }
}

/** move the enemies */
void Game::ennemiesWalk()
{
    for(Enemies* enemy : mapOfGame->getEnemies())
    {
        enemy->walk();
    }
}

/** the enemies attack the king */
void Game::ennemiesAttack()
{
    for(Enemies* enemy:mapOfGame->getEnemies())
    {
        enemy->attackKing(mapOfGame->getKing());
    }
}

/** attack the enemies who is nearby (inused) */
void Game::towerAttack()
{
    for(Tower* tower:mapOfGame->getTowers())
    {
        for(Enemies* enemy:mapOfGame->getEnemies())
        {
            if(tower->isInRange(enemy->getX(),0))
            {
                tower->attackEnemy(*enemy);
            }
        }
    }
}

/** detect if is the end of wave */
bool Game::IsEndOfWave()
{
    for(Enemies *enemy:mapOfGame->getEnemies())
    {
        if(!dynamic_cast<StateDie*>(enemy->getState()))
        {
            return false;
        }
    }
    return true;
}

/** cuts the game when the player has lost (when the king is dead) */
bool Game::isGameOver()
{
    if(mapOfGame->getKing().getHealth()<=0)
    {
        return true;
    }
    return false;
}

/** increase the speed of game */
void Game::increaseGameSpeed()
{
    if(gameSpeed<3)
    {
        gameSpeed++;
    }
}

/** decrease the speed of game */
void Game::decreaseGameSpeed()
{
    if(gameSpeed>1)
    {
        gameSpeed--;
    }
}

