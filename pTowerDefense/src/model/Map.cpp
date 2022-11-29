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

void Map::addTower(int x, int y, TypeOfTower type)
{
    switch(type)
    {
        case earth:
        {
             listOfTower.push_back(new TowerEarth(x,y));
             break;
        }

        case ice:
        {
            listOfTower.push_back(new TowerIce(x,y));
            break;
        }

        case sand:
        {
            listOfTower.push_back(new TowerSand(x,y));
            break;
        }

        case iron:
        {
            listOfTower.push_back(new TowerIron(x,y));
            break;
        }
    }
}

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
        cout << "this tower is not in the list/map" << endl;
    }
    return false;
}

/* delete all enemies  */
void Map::deleteAllEnemies()
{
    for(Enemies *enemy: listOfEnemies)
    {
        delete enemy;
    }
    listOfEnemies.clear();
}

/*improve statistics of all enemies */
void Map::improveAllEnemies(int numeroOfWave)
{
    for(Enemies *enemy: listOfEnemies)
    {
        enemy->improveStatistics(numeroOfWave);
    }
}
/* return the first enemy not dead and who is the who is the closest to the king and too in range of tower, that is to say the farthest on the map else
return -1*/
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
