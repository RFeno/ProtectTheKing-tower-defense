#include "Map.h"
#include <string>
#include <iostream>
#include "Ogre.h"
#include "Orc.h"
#include "ShadowMonster.h"
#include "KnightOfDeath.h"
#include "Gremlin.h"
#include <Tower.h>
#include <Enemies.h>
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
    for(Enemies *en: listOfEnemies)
    {
        result+= en->getInformations()+"\n";
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

void Map::addTower(Tower* tower)
{
    listOfTower.push_back(tower);
}
