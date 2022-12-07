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
        int getFirstEnemyNotDead(Tower &tower);
        bool isTowerPositonAlreadyUsed(int position);
        void calculPositionOfNewTower(TypeOfTowerPrice type, int position);
        void calculPositionOfEarth(int position);
        void calculPositionOfIron(int position);
        void calculPositionOfIce(int position);
        void calculPositionOfSand(int position);
        bool isAllPlacesOccupied();
        void confrontationTowersEnemies();
        void confrontationEnemiesKing();
        int getMiddlePositionOfTower(Tower &tower);


        //getters and setters
        std::vector<Tower*> getTowers()const
        {
            return listOfTower;
        }

        std::vector<Enemies*> getEnemies()const
        {
            return listOfEnemies;
        }

        King &getKing()const
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

        /**AIP because the enemy are only accessible by the map */
        std::vector<Tower*> listOfTower;
        std::vector<Enemies*> listOfEnemies;
        King *king;

        int xOfTheNextTower;
        int yOfTheNextTower;

};

#endif // MAP_H
