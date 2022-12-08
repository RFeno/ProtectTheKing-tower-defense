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

    numeroOfWave = 0;
    gameSpeed = 1;
    gamePaused = false;
    fireSpellActive = false;
    acidCloudSpellActive = false;
    lightningSpellActive = false;
    numberOfEnemiesSpawned = 0;
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
    this->numeroOfWave = other.numeroOfWave;
    this->gameSpeed = other.gameSpeed;
    this->gamePaused = other.gamePaused;
    this->fireSpellActive = other.fireSpellActive;
    this->acidCloudSpellActive = other.acidCloudSpellActive;
    this->lightningSpellActive = other.lightningSpellActive;
    this->numberOfEnemiesSpawned = other.numberOfEnemies;
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
    this->numeroOfWave = rhs.numeroOfWave;
    this->gameSpeed = rhs.gameSpeed;
    this->gamePaused = rhs.gamePaused;
    this->fireSpellActive = rhs.fireSpellActive;
    this->acidCloudSpellActive = rhs.acidCloudSpellActive;
    this->lightningSpellActive = rhs.lightningSpellActive;
    this->numberOfEnemiesSpawned = rhs.numberOfEnemies;

    //assignment operator
    return *this;
}

/** launch the wave, generate enemies*/
void Game::createWave()
{
    numeroOfWave++;
    cout << "CREATE WAVE NUMERO:  " << numeroOfWave << endl;

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

/** detect if is the end of wave */
bool Game::isEndOfWave()
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

/** increase the number of enemeis who are spawned on the map*/
void Game::increaseNumberOfEnemiesSpawned()
{
    numberOfEnemiesSpawned++;
}

/** removes enemies then spawns 10 new ones and finally upgrades enemies to match wave difficulty level, reset the number of enemies spawned */
void Game::refreshEnemies()
{
    //delete all enemies who are dead
    mapOfGame->deleteAllEnemies();

    //create a new wave with 10 enemies
    createWave();

    //improve statistics of all enemies
    mapOfGame->improveAllEnemies(numeroOfWave);

    //reset number of enemies who are spawn
    numberOfEnemiesSpawned=0;
}

/** decrease the wallet of player */
void Game::debitPlayerWallet(int price)
{
    player->setCoins(player->getCoins()-price);
}

/** increase the wallet of player */
void Game::creditPlayerWallet(int price)
{
    player->setCoins(player->getCoins()+price);
}

/** increase the gems and the score of the player when he kills a enemy */
void Game::increasePlayerStatsWhenEnemyKilled()
{
    for(Enemies* e: getMap()->getEnemies())
    {
        if(e->getHealth() == 0 && !e->isCounted())
        {
            creditPlayerWallet(e->getMarketValue());
            getPlayer()->addScore(e->getScoreValue());
            getPlayer()->setNumberOfEnemyKilled(getPlayer()->getNumberOfEnemyKilled()+1);
            e->setCounted(true);
        }
    }
}

/** incrase the score of player */
void Game::increasePlayerScore(int value)
{
    player->addScore(value);
}

/** reset the game to be able to restart the game */
void Game::resetGame()
{
    //give enough coins to buy sand tower
    player->setCoins(sand);

    player->setScore(0);

    player->setNumberOfEnemyKilled(0);

    player->clearListOfSpells();

    player->updateSpellsNumber();

    mapOfGame->deleteAllEnemies();
    mapOfGame->deleteAllTowers();
    mapOfGame->getKing().setHealth(mapOfGame->getKing().getKingHealthMax());
    numeroOfWave=0;
}

/** allow the player to attack enemies with spells*/
bool Game::spellAttack(TypeOfSpell type, DamageOfSpell damage)
{
    if(player->removeSpell(type))
    {
        mapOfGame->spellAttack(damage);
        return true;
    }
    return false;
}
