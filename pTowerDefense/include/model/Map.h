#ifndef MAP_H
#define MAP_H
#include "Tower.h"
#include "Enemies.h"
#include <list>
#include <vector>

class Map
{
    public:

        //canonique
        Map();
        virtual ~Map();
        Map(const Map& other);
        Map& operator=(const Map& other);

        //methods
        std::string strEnemies()const;
        void addEnemy(typeOfEnemies type);
        void addTower(Tower* tower);
        bool removeEnemy(Enemies &enemy);
        int searchEnemy(const Enemies &enemy);

        //getters and setters
        //pointeurs ou référence
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
