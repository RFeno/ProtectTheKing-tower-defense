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

    //after each wave this number will be incremented
    numeroOfWave = 0;

    numberOfEnemies = 0;

}
//dtor
Game::~Game()
{
    delete player;
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
/* launch the wave, generate enemies*/
void Game::createWave()
{
    numeroOfWave++;
    numberOfEnemies += rand()%5 +1;

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

            default:
                cout << "error the create enemies for wave " << endl;
        }
    }
}

void Game::play()
{
    cout << "GAME PLAY" << endl;
    if(IsEndOfWave())
    {
        createWave();
        cout << "CREATE WABE NUMBER ==> " << numeroOfWave << endl;
    }

    //delete enemies dead
    for(Enemies *enemy: mapOfGame->getEnemies())
    {
        if(dynamic_cast<StateDie*>(enemy->getState()))
        {
            cout << "delete enemy " << to_string(enemy->getId());
            if(mapOfGame->removeEnemy(*enemy))
            {
                cout << " with success" << endl;
            }
            else
            {
                cout << " with fail" << endl;
            }
        }
    }

    //move enemies
    if(mapOfGame->getEnemies().size() > 0)
    {
        ennemiesWalk();
        cout << "walk of enemies" << endl;

    }

    //tower attack

    if(mapOfGame->getTowers().size() > 0)
    {
        towerAttack();
        cout << "attack of tower" << endl;
    }
}

void Game::ennemiesWalk()
{
    for(Enemies* enemy : mapOfGame->getEnemies())
    {
        enemy->walk();
    }
}

void Game::ennemiesAttack()
{
    for(Enemies* enemy:mapOfGame->getEnemies())
    {
        enemy->attackKing(mapOfGame->getKing());
    }
}
/** attack the enemies who is nearby */
void Game::towerAttack()
{
    for(Tower* tower:mapOfGame->getTowers())
    {
        for(Enemies* enemy:mapOfGame->getEnemies())
        {
            if(tower->isInRange(enemy->getX()))
            {
                tower->attackEnemy(*enemy);
            }
        }
    }
}


/* detect if is the end of wave */
bool Game::IsEndOfWave()
{
    if(mapOfGame->getEnemies().size()==0)
    {
        return true;
    }
    return false;
}

/*cuts the game when the player has lost (when the king is dead) */
bool Game::isGameOver()
{
    return false;
}


