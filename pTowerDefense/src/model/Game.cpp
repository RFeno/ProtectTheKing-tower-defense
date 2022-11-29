#include "Game.h"
#include "Player.h"
#include "King.h"
#include "Map.h"
#include <string>
#include <iostream>

#include "State.h"
#include "StateDie.h"

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
/** DEMANDER AU PROF SI BESOIN DE TOUTES LES CLASSES CANONIQUES OU PAS*/
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
/* launch the wave, generate enemies*/
void Game::createWave()
{
    numeroOfWave++;

    for(int i = 1; i<= numberOfEnemies;i++)
    {
        int typeOfEnemy = rand()%5 +1;

        //creation of ennemies randomly
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

/**
* move the enemies
*/
void Game::ennemiesWalk()
{
    for(Enemies* enemy : mapOfGame->getEnemies())
    {
        //call the state
        enemy->walk();
    }
}

/* the enemies attack the king */
void Game::ennemiesAttack()
{
    for(Enemies* enemy:mapOfGame->getEnemies())
    {
        enemy->attackKing(mapOfGame->getKing());
    }
}

/**
attack the enemies who is nearby (inused)
*/
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

/**
 detect if is the end of wave
*/
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

/**
*cuts the game when the player has lost (when the king is dead)
*/
bool Game::isGameOver()
{
    if(mapOfGame->getKing().getHealth()<=0)
    {
        return true;
    }
    return false;
}


