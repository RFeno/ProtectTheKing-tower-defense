#include "Map.h"
#include <string>
#include <iostream>
using namespace std;

Map::Map()
{
    //ctor
}

Map::~Map()
{
    //dtor

    for(list<Enemies*>::iterator it = listOfEnemies.begin(); it!=listOfEnemies.end() ; it++)
    {
       delete *it;
    }

    for(list<Tower*>::iterator it = listOfTower.begin(); it!=listOfTower.end() ; it++)
    {
       delete *it;
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
    string result ="list of enemies\n";
    for(Enemies* en: listOfEnemies)
    {
        result+= en->getInformations();
        //to delete
        //cout << en->getInformations() << endl;
    }
    return result;
}

