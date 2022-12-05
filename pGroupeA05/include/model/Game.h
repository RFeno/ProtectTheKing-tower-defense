#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "King.h"
#include "Map.h"

#include <string>

class Game
{
    public:
        static const int spawnTime = 3;

        Game();
        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        //mehtods
        void resetGame();
        bool isGameOver();
        void createWave();
        void ennemiesWalk();
        void towerAttack();
        void ennemiesAttack();
        bool isEndOfWave();
        void increaseGameSpeed();
        void decreaseGameSpeed();
        void increaseNumberOfEnemiesSpawned();
        void increaseGemsWhenEnemyKilled();
        void refreshEnemies();
        void debitPlayerWallet(int valueOfDebit);
        void creditPlayerWallet(int valueOfCredit);
        void increasePlayerScore(int valueToAdd);





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

        std::string getMessage()
        {
            return message;
        }

        void setGamePaused(bool pause)
        {
            gamePaused=pause;
        }

        void setNumberOfEnemiesSpawn(int spawn)
        {
            numberOfEnemiesSpawned=spawn;
        }

        void setMessage(std::string message)
        {
            this->message=message;
        }



    protected:

    private:
        Player *player;
        Map *mapOfGame;
        const int numberOfEnemies =10;
        int numeroOfWave = 0;
        int gameSpeed = 1;
        bool gamePaused = false;
        int numberOfEnemiesSpawned = 0;
        std::string message;


};

#endif // GAME_H
