#ifndef MAP_H
#define MAP_H
#include "Tower.h"
#include "Enemies.h"
#include <list>
#include <vector>
class Map
{
    public:

        Map();
        virtual ~Map();
        Map(const Map& other);
        Map& operator=(const Map& other);

        //methods
        std::string strEnemies()const;
        void addEnemy(const Enemies* enemy);
        void addTower(const Tower* tower);

        //getters and setters
        std::vector<Tower*> getTowers()const
        {
            return listOfTower;
        }

        std::vector<Enemies*> getEnemies()const
        {
            return listOfEnemies;
        }

    protected:

    private:
        std::vector<Tower*> listOfTower;
        std::vector<Enemies*> listOfEnemies;

};

#endif // MAP_H
