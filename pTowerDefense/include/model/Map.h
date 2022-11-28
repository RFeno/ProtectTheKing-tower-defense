#ifndef MAP_H
#define MAP_H

#include "Tower.h"
#include "Enemies.h"
#include "King.h"

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
        std::string strTowers()const;
        void addEnemy(typeOfEnemies type);
        void addTower(int x, int y, TypeOfTower type);
        bool removeEnemy(Enemies &enemy);
        int searchEnemy(Enemies &enemy);
        void deleteAllEnemies();
        void improveAllEnemies(int numeroOfWave);

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

        King &getKing()
        {
            return *king;
        }

    protected:

    private:
        std::vector<Tower*> listOfTower;
        std::vector<Enemies*> listOfEnemies;
        King *king;

};

#endif // MAP_H
