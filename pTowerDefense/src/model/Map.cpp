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

//   for(Enemies* enemy: *listOfEnemies)
//   {
//        delete enemy;
//   }
//
//   for(Tower* tower: *listOfTower)
//   {
//       delete tower;
//   }
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

