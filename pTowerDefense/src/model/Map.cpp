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
}

Map::~Map()
{
    //dtor
    //double delete ? because delete in game and here ?
    if(listOfEnemies.size() < 0)
    {
         for(Enemies* enemy: listOfEnemies)
       {
            delete enemy;
       }
    }

    if(listOfTower.size() > 0)
    {
        for(Tower* tower: listOfTower)
        {
            delete tower;
        }
   }
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
    string result ="list of enemies[\n";
    for(Enemies *en: listOfEnemies)
    {
        result+= en->getInformations() +"\n";
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

void Map::addTower(Tower* tower)
{
    listOfTower.push_back(tower);
}
