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
}

Map::~Map()
{
    //dtor
    for(Enemies* enemy: listOfEnemies)
    {
        delete enemy;
    }

    for(Tower* tower: listOfTower)
    {
        delete tower;
    }

    delete king;

}

Map::Map(const Map& other)
{
    //copy ctor
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
        this->listOfEnemies.push_back(enemy);
    }

    for(Tower* tower: rhs.listOfTower)
    {
        this->listOfTower.push_back(tower);
    }

    delete king;
    this->king=rhs.king;

    //assignment operator
    return *this;
}

string Map::strEnemies()const
{
    string result ="list of enemies\n[\n";
    for(Enemies *enemy: listOfEnemies)
    {
        result+= enemy->getInformations()+"\n";
    }
    return result+="]";
}

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
void Map::addTower(TypeOfTower type,int position)
{
    //change the value of yOfTheNextTower and xOfTheNextTower
    getPositionOfNewTower(type,position);

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
int Map::getFirstEnemyNotDead(Tower &tower, int middleOfTower)
{
    for(int i=0;i<(int)listOfEnemies.size();i++)
    {
        if(!dynamic_cast<StateDie*>(listOfEnemies[i]->getState()))
        {
            int xOfenemy = listOfEnemies[i]->getX();

            if(tower.isInRange(xOfenemy,middleOfTower))
            {
                bool isTheFarthest = true;

                for(int j=0;j<(int)listOfEnemies.size();j++)
                {
                    int xOfSecondEnemy = listOfEnemies[j]->getX();

                    if(xOfenemy < xOfSecondEnemy && tower.isInRange(xOfSecondEnemy,middleOfTower) && !dynamic_cast<StateDie*>(listOfEnemies[j]->getState()))
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
void Map::getPositionOfNewTower(TypeOfTower type, int position)
{
    switch(type)
    {
        case earth:
            getPositionOfEarth(position);
            break;
        case iron:
            getPositionOfIron(position);
            break;
        case ice:
            getPositionOfIce(position);
            break;
        case sand:
            getPositionOfSand(position);
            break;
    }
    //cout << "X vaut " << to_string(x) << " Y vaut " << to_string(y) << endl;
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::getPositionOfEarth(int position)
{
    switch(position-1)
    {
        case 3:
        {
            xOfTheNextTower=100;
            yOfTheNextTower=370-75;
            break;
        }
        case 2:
        {
            xOfTheNextTower=350;
            yOfTheNextTower=370-75;
            break;
        }
        case 1:
        {
            xOfTheNextTower=650;
            yOfTheNextTower=370-75;
            break;
        }
        case 0:
        {
            xOfTheNextTower=990;
            yOfTheNextTower=370-75;
            break;
        }
        case 6:
        {
            xOfTheNextTower=40;
            yOfTheNextTower=600-75;
            break;
        }
        case 5:
        {
            xOfTheNextTower=300;
            yOfTheNextTower=600-75;
            break;
        }
        case 4:
        {
            xOfTheNextTower=975;
            yOfTheNextTower=600-75;
            break;
        }
    }
}

/**
this method defines a position in x and yOfTheNextTower to display the tower in the right place on the map
*/
void Map::getPositionOfIce(int position)
{
    switch(position-1)
    {
        case 3:
            {
                xOfTheNextTower=100 +5;
                yOfTheNextTower=385 -80;
                break;
            }
        case 2:
            {
                xOfTheNextTower=350 +5;
                yOfTheNextTower=385 -80;
                break;
            }
        case 1:
            {
                xOfTheNextTower=650 +5;
                yOfTheNextTower=385 -80;
                break;
            }
        case 0:
            {
                xOfTheNextTower=990 +5;
                yOfTheNextTower=385 -80;
                break;
            }
        case 6:
            {
                xOfTheNextTower=40;
                yOfTheNextTower=630 -80;
                break;
            }
        case 5:
            {
                xOfTheNextTower=300;
                yOfTheNextTower=630 -80;
                break;
            }
        case 4:
            {
                xOfTheNextTower=975;
                yOfTheNextTower=625 -80;
                break;
            }
    }
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::getPositionOfIron(int position)
{
    switch(position-1)
    {
        case 3:
        {
            xOfTheNextTower=100 +10;
            yOfTheNextTower=330 -28;
            break;
        }
        case 2:
        {
            xOfTheNextTower=360 +10;
            yOfTheNextTower=330 -28;
            break;
        }
        case 1:
        {
            xOfTheNextTower=660 +10;
            yOfTheNextTower=330 -28;
            break;
        }
        case 0:
        {
            xOfTheNextTower=990 +7;
            yOfTheNextTower=330 -28;
            break;
        }
        case 6:
        {
            xOfTheNextTower=38 ;
            yOfTheNextTower=575 -30;
            break;
        }
        case 5:
        {
            xOfTheNextTower=297 ;
            yOfTheNextTower=575 -30;
            break;
        }
        case 4:
        {
            xOfTheNextTower=980 +5;
            yOfTheNextTower=575 -30;
            break;
        }
    }
}

/**
this method defines a position in x and y to display the tower in the right place on the map
*/
void Map::getPositionOfSand(int position)
{
    switch(position-1)
    {
        case 3:
            {
                xOfTheNextTower=100;
                yOfTheNextTower=340 -35;
                break;
            }
        case 2:
            {
                xOfTheNextTower=360;
                yOfTheNextTower=340 -35;
                break;
            }
        case 1:
            {
                xOfTheNextTower=660;
                yOfTheNextTower=340 -35;
                break;
            }
        case 0:
            {
                xOfTheNextTower=990;
                yOfTheNextTower=340 -35;
                break;
            }
        case 6:
            {
                xOfTheNextTower=40;
                yOfTheNextTower=575 -35;
                break;
            }
        case 5:
            {
                xOfTheNextTower=300;
                yOfTheNextTower=575 -35;
                break;
            }
        case 4:
            {
                xOfTheNextTower=975;
                yOfTheNextTower=575 -35;
                break;
            }
    }
}