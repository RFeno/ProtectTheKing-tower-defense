#include <string>
#include <iostream>

#include "Map.h"
#include "StateDie.h"

/**ENEMIES */
#include "Enemies.h"
#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"

/** TOWERS */
#include "Tower.h"
#include "TowerEarth.h"
#include "TowerIce.h"
#include "TowerIron.h"
#include "TowerSand.h"

using namespace std;

Map::Map()
{
    //ctor
    this->king = new King();
    xOfTheNextTower =0;
    yOfTheNextTower = 0;
}

Map::~Map()
{
    //dtor
    for(Enemies* enemy: listOfEnemies)
    {
        delete enemy;
    }

    listOfEnemies.clear();

    for(Tower* tower: listOfTower)
    {
        delete tower;
    }

    listOfTower.clear();

    delete king;

}

Map::Map(const Map& other): xOfTheNextTower(other.xOfTheNextTower), yOfTheNextTower(other.yOfTheNextTower)
{
    //copy ctor
    for(Enemies *enemy:other.listOfEnemies)
    {
        listOfEnemies.push_back(enemy->clone());
    }

    for(Tower *tower:listOfTower)
    {
        listOfTower.push_back(tower->clone());
    }
}

Map& Map::operator=(const Map& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    for(Enemies* enemy: listOfEnemies)
    {
        delete enemy;
    }

    for(Tower* tower: listOfTower)
    {
        delete tower;
    }

    this->listOfEnemies.clear();
    this->listOfTower.clear();

    for(Enemies* enemy: rhs.listOfEnemies)
    {
        this->listOfEnemies.push_back(enemy->clone());
    }

    for(Tower* tower: rhs.listOfTower)
    {
        this->listOfTower.push_back(tower->clone());
    }

    delete king;
    this->king=rhs.king->clone();

    //assignment operator
    return *this;
}
/** return the state of enemies (informations) */
string Map::strEnemies()const
{
    string result ="list of enemies\n[\n";
    for(Enemies *enemy: listOfEnemies)
    {
        result+= enemy->getInformations()+"\n";
    }
    return result+="]";
}

/** return the state of towers (informations) */
string Map::strTowers()const
{
    string result ="list of towers\n[\n";
    for(Tower *tower: listOfTower)
    {
        result+= tower->toString()+"\n";
    }
    return result+="]";
}

/** add the new enemy on the map list in terms of the type of enemy */
void Map::addEnemy(typeOfEnemies type)
{
    switch(type)
    {
        case gremlinValue:
        {
            listOfEnemies.push_back(new Gremlin());
            break;
        }

        case knightOfDeathValue:
        {
            listOfEnemies.push_back(new KnightOfDeath());
            break;
        }

        case ogreValue:
        {
            listOfEnemies.push_back(new Ogre());
            break;
        }

        case orcValue:
        {
            listOfEnemies.push_back(new Orc());
            break;
        }
        case shadowMonsterValue:
        {
            listOfEnemies.push_back(new ShadowMonster());
            break;
        }
    }
}

/** return the index of enemy on the map else -1 */
int Map::searchEnemy(Enemies& enemy)
{
    int result = -1;

    for(size_t i=0;i<listOfEnemies.size();i++)
    {
        if(listOfEnemies[i]==&enemy)
        {
            result=i;
            break;
        }
    }
    return result;
}
/** remove the enemy on the map list*/
bool Map::removeEnemy(Enemies& enemy)
{
    int index = searchEnemy(enemy);

    if(index!=-1)
    {
        Enemies *tmp = *(listOfEnemies.begin() + index);
        listOfEnemies.erase(listOfEnemies.begin()+index);
        delete tmp;

        return true;
    }
    else
    {
        cout << "this enemy is not in the list/map" << endl;
    }
    return false;
}

/** add a new tower on the map */
void Map::addTower(TypeOfTowerPrice type,int position)
{
    //change the value of yOfTheNextTower and xOfTheNextTower
    calculPositionOfNewTower(type,position);

    switch(type)
    {
        case earth:
        {
            listOfTower.push_back(new TowerEarth(xOfTheNextTower,yOfTheNextTower,position));
            break;
        }

        case ice:
        {
            listOfTower.push_back(new TowerIce(xOfTheNextTower,yOfTheNextTower,position));
            break;
        }

        case sand:
        {
            listOfTower.push_back(new TowerSand(xOfTheNextTower,yOfTheNextTower,position));
            break;
        }

        case iron:
        {
            listOfTower.push_back(new TowerIron(xOfTheNextTower,yOfTheNextTower,position));
            break;
        }
    }
}
/** return the index of the tower on the map else return -1*/
int Map::searchTower(Tower &tower)
{
    int result = -1;

    for(size_t i=0;i<listOfTower.size();i++)
    {
        if(listOfTower[i]==&tower)
        {
            result=i;
            break;
        }
    }
    return result;
}
/** remove the tower at the map */
bool Map::removeTower(Tower &tower)
{
    int index = searchTower(tower);

    if(index!=-1)
    {
        Tower *tmp = *(listOfTower.begin() + index);
        listOfTower.erase(listOfTower.begin()+index);
        delete tmp;

        return true;
    }
    else
    {
        cout << "this tower is not in the list" << endl;
    }
    return false;
}

/**delete all enemies  */
void Map::deleteAllEnemies()
{
    for(Enemies *enemy: listOfEnemies)
    {
        delete enemy;
    }
    listOfEnemies.clear();
}

/**improve statistics of all enemies */
void Map::improveAllEnemies(int numeroOfWave)
{
    for(Enemies *enemy: listOfEnemies)
    {
        enemy->improveStatistics(numeroOfWave);
    }
}

/**return the first enemy not dead and who is the who is the closest to the king and too in range of tower,
that is to say the farthest on the map else return -1
take in parameter the tower which wants to attack as well as the middle of the size of the image of the tower*/
int Map::getFirstEnemyNotDead(Tower &tower)
{
    for(int i=0;i<(int)listOfEnemies.size();i++)
    {
        if(!dynamic_cast<StateDie*>(listOfEnemies[i]->getState()))
        {
            int xOfenemy = listOfEnemies[i]->getX();

            if(tower.isInRange(xOfenemy,getMiddlePositionOfTower(tower)))
            {
                bool isTheFarthest = true;

                for(int j=0;j<(int)listOfEnemies.size();j++)
                {
                    int xOfSecondEnemy = listOfEnemies[j]->getX();

                    if(xOfenemy < xOfSecondEnemy && tower.isInRange(xOfSecondEnemy,getMiddlePositionOfTower(tower)) && !dynamic_cast<StateDie*>(listOfEnemies[j]->getState()))
                    {
                        isTheFarthest=false;
                        break;
                    }
                }

                if(isTheFarthest)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

/** return if the position is aleready used by a another tower on the map*/
bool Map::isTowerPositonAlreadyUsed(int position)
{
    for(Tower *tower:listOfTower)
    {
        if(tower->getPosition() == position)
        {
            return true;
        }
    }
    return false;
}

/**
*depending on the type of tower the player wants to buy
*this method will call the correct method which will change an x and y position
*/
void Map::calculPositionOfNewTower(TypeOfTowerPrice type, int position)
{
    switch(type)
    {
        case earth:
            calculPositionOfEarth(position);
            break;
        case iron:
            calculPositionOfIron(position);
            break;
        case ice:
            calculPositionOfIce(position);
            break;
        case sand:
            calculPositionOfSand(position);
            break;
    }
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::calculPositionOfEarth(int position)
{
    switch(position-1)
    {
        case 0:
        {
            xOfTheNextTower=100;
            yOfTheNextTower=295;
            break;
        }
        case 1:
        {
            xOfTheNextTower=360;
            yOfTheNextTower=295;
            break;
        }
        case 2:
        {
            xOfTheNextTower=660;
            yOfTheNextTower=295;
            break;
        }
        case 3:
        {
            xOfTheNextTower=990;
            yOfTheNextTower=295;
            break;
        }
        case 4:
        {
            xOfTheNextTower=40;
            yOfTheNextTower=525;
            break;
        }
        case 5:
        {
            xOfTheNextTower=300;
            yOfTheNextTower=525;
            break;
        }
        case 6:
        {
            xOfTheNextTower=975;
            yOfTheNextTower=525;
            break;
        }
    }
}

/**
this method defines a position in x and yOfTheNextTower to display the tower in the right place on the map
*/
void Map::calculPositionOfIce(int position)
{
    switch(position-1)
    {
        case 0:
            {
                xOfTheNextTower=105;
                yOfTheNextTower=305;
                break;
            }
        case 1:
            {
                xOfTheNextTower=355;
                yOfTheNextTower=305;
                break;
            }
        case 2:
            {
                xOfTheNextTower=655;
                yOfTheNextTower=305;
                break;
            }
        case 3:
            {
                xOfTheNextTower=995;
                yOfTheNextTower=305;
                break;
            }
        case 4:
            {
                xOfTheNextTower=40;
                yOfTheNextTower=550;
                break;
            }
        case 5:
            {
                xOfTheNextTower=300;
                yOfTheNextTower=550;
                break;
            }
        case 6:
            {
                xOfTheNextTower=975;
                yOfTheNextTower=550;
                break;
            }
    }
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::calculPositionOfIron(int position)
{
    switch(position-1)
    {
        case 0:
        {
            xOfTheNextTower=110;
            yOfTheNextTower=302;
            break;
        }
        case 1:
        {
            xOfTheNextTower=370;
            yOfTheNextTower=302;
            break;
        }
        case 2:
        {
            xOfTheNextTower=670;
            yOfTheNextTower=302;
            break;
        }
        case 3:
        {
            xOfTheNextTower=997;
            yOfTheNextTower=302;
            break;
        }
        case 4:
        {
            xOfTheNextTower=38;
            yOfTheNextTower=545;
            break;
        }
        case 5:
        {
            xOfTheNextTower=297;
            yOfTheNextTower=545;
            break;
        }
        case 6:
        {
            xOfTheNextTower=985;
            yOfTheNextTower=545;
            break;
        }
    }
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::calculPositionOfSand(int position)
{
    switch(position-1)
    {
        case 0:
        {
            xOfTheNextTower=100;
            yOfTheNextTower=305;
            break;
        }
        case 1:
        {
            xOfTheNextTower=360;
            yOfTheNextTower=305;
            break;
        }
        case 2:
        {
            xOfTheNextTower=660;
            yOfTheNextTower=305;
            break;
        }
        case 3:
        {
            xOfTheNextTower=990;
            yOfTheNextTower=305;
            break;
        }
        case 4:
        {
            xOfTheNextTower=40;
            yOfTheNextTower=540;
            break;
        }
        case 5:
        {
            xOfTheNextTower=300;
            yOfTheNextTower=540;
            break;
        }
        case 6:
        {
            xOfTheNextTower=975;
            yOfTheNextTower=540;
            break;
        }
    }
}

/**delete all towers of map*/
void Map::deleteAllTowers()
{
    for(Tower *tower: listOfTower)
    {
        delete tower;
    }
    listOfTower.clear();
}

/** return if all towers places are occupied*/
bool Map::isAllPlacesOccupied()
{
    if(listOfTower.size()>6)
    {
        return true;
    }

    return false;
}

/**clone the map*/
Map* Map::clone()const
{
    return new Map(*this);
}

/** confrontation between towers and enemies */
void Map::confrontationTowersEnemies()
{
    for(Tower *tower:listOfTower)
    {
        for(Enemies *enemy: listOfEnemies)
        {
            if(tower->isInRange(enemy->getX(),getMiddlePositionOfTower(*tower)))
            {
                ///allow to attack only if the enemy is the first and the farthest
                if(getFirstEnemyNotDead(*tower) == searchEnemy(*enemy))
                {
                    tower->setAttacking(true);
                    tower->attackEnemy(*enemy);
                }
                else
                {
                    tower->setAttacking(false);
                }
            }
        }
    }
}

/** confrontation between enemies and king */
void Map::confrontationEnemiesKing()
{
    for(Enemies *enemy: listOfEnemies)
    {
        enemy->attackKing(*king);
    }
}

/** depending on the type of the tower, returns half its size to calculate the range*/
int Map::getMiddlePositionOfTower(Tower &tower)
{
    if(dynamic_cast<TowerEarth*>(&tower))
    {
        return 87;
    }
    else
    {
        if(dynamic_cast<TowerSand*>(&tower))
        {
            return 88;
        }
        else
        {
            if(dynamic_cast<TowerIce*>(&tower))
            {
                return 89;
            }
            else
            {
                if(dynamic_cast<TowerIron*>(&tower))
                {
                    return 81;
                }
                else
                {
                   return 0;
                }
            }
        }
    }
}
