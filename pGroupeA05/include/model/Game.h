#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player.h"
#include "King.h"
#include "Map.h"

class Game
{
    public:
        static const int spawnTime = 3;

        Game();

        //mehtods
        bool isGameOver();
        void createWave();
        void ennemiesWalk();
        void towerAttack();
        void ennemiesAttack();
        bool IsEndOfWave();
        void increaseGameSpeed();
        void decreaseGameSpeed();
        void increaseNumberOfEnemiesSpawned();
        void refreshEnemies();

        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);



        Map* getMap()const
        {
            return mapOfGame;
        }

        Player* getPlayer()const
        {
            return player;
        }

        int getNumberOfEnemies()const
        {
            return numberOfEnemies;
        }

        int getNumeroOfWave()
        {
            return numeroOfWave;
        }

        int getGameSpeed()
        {
            return gameSpeed;
        }

        int getNumberOfEnemiesSpawned()
        {
            return numberOfEnemiesSpawned;
        }

        int getSpawnTime()
        {
            return spawnTime;
        }

        bool getGamePaused()
        {
            return gamePaused;
        }

        void setGamePaused(bool pause)
        {
            gamePaused=pause;
        }

        void setNumberOfEnemiesSpawn(int spawn)
        {
            numberOfEnemiesSpawned=spawn;
        }

    protected:

    private:
        Player *player;
        Map *mapOfGame;
        const int numberOfEnemies =10;
        int numeroOfWave = 30;
        int gameSpeed = 1;
        bool gamePaused = false;
        int numberOfEnemiesSpawned = 0;


};

#endif // GAME_H
