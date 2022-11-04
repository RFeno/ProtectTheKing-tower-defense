#ifndef MAP_H
#define MAP_H
#include "Tower.h"
#include "Enemies.h"
#include <list>

class Map
{
    public:
        Map();
        virtual ~Map();
        Map(const Map& other);
        Map& operator=(const Map& other);

        std::list<Tower*> getTowers()const
        {
            return listOfTower;
        }

        std::list<Enemies*> getEnemies()const
        {
            return listOfEnemies();
        }

    protected:

    private:
        std::list<Tower*> listOfTower;
        std::list<Enemies*> listOfEnemies;
};

#endif // MAP_H
