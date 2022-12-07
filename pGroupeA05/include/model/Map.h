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
        Map();
        virtual ~Map();
        Map(const Map& other);
        Map& operator=(const Map& other);

        /**methods*/
        std::string strEnemies()const;
        std::string strTowers()const;
        Map *clone()const;


        ///ENEMIES
        void addEnemy(typeOfEnemies type);
        bool removeEnemy(Enemies &enemy);
        int searchEnemy(Enemies &enemy);
        void deleteAllEnemies();
        void improveAllEnemies(int numeroOfWave);

        ///TOWERS
        bool removeTower(Tower &tower);
        void deleteAllTowers();
        int searchTower(Tower &tower);
        void addTower(TypeOfTowerPrice type,int positon);
        int getFirstEnemyNotDead(Tower &tower,int middleOfTower);
        bool isTowerPositonAlreadyUsed(int position);
        void getPositionOfNewTower(TypeOfTowerPrice type, int position);
        void getPositionOfEarth(int position);
        void getPositionOfIron(int position);
        void getPositionOfIce(int position);
        void getPositionOfSand(int position);
        bool isAllPlacesOccupied();

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

        int getXOftheNextTower()const
        {
            return xOfTheNextTower;
        }

        int getYOftheNextTower()const
        {
            return yOfTheNextTower;
        }

    protected:

    private:
        std::vector<Tower*> listOfTower;
        std::vector<Enemies*> listOfEnemies;
        King *king;

        int xOfTheNextTower;
        int yOfTheNextTower;

};

#endif // MAP_H
