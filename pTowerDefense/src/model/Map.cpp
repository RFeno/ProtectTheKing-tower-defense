#include "Map.h"
#include <string>
#include <iostream>


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
   /*for(Enemies* enemy: listOfEnemies)
   {
        delete enemy;
   }

   for(Tower* tower: listOfTower)
   {
       delete tower;
   }*/
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

void Map::addEnemy(const Enemies* enemy)
{
    listOfEnemies.push_back(enemy->clone());
}

void Map::addTower(const Tower* tower)
{
    listOfTower.push_back(tower->clone());
}
