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

        /**methods*/
        std::string strEnemies()const;
        std::string strTowers()const;
        void addEnemy(typeOfEnemies type);
        void addTower(int x, int y, TypeOfTower type,int positon);
        bool removeEnemy(Enemies &enemy);
        int searchEnemy(Enemies &enemy);
        bool removeTower(Tower &tower);
        int searchTower(Tower &tower);

        ///ENEMIES
        void deleteAllEnemies();
        void improveAllEnemies(int numeroOfWave);

        ///TOWERS
        int getFirstEnemyNotDead(Tower &tower,int middleOfTower);
        bool isTowerPositonAlreadyUsed(int position);
        void getPositionOfNewTower(TypeOfTower type, int position);
        void getPositionOfEarth(int position);
        void getPositionOfIron(int position);
        void getPositionOfIce(int position);
        void getPositionOfSand(int position);

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
