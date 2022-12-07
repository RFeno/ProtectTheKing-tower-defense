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

        //default constructor
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
        void increasePlayerStatsWhenEnemyKilled();
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

        int getNumeroOfWave()const
        {
            return numeroOfWave;
        }

        int getGameSpeed()const
        {
            return gameSpeed;
        }

        int getNumberOfEnemiesSpawned()const
        {
            return numberOfEnemiesSpawned;
        }

        int getSpawnTime()const
        {
            return spawnTime;
        }

        bool isGamePaused()const
        {
            return gamePaused;
        }

        bool isFireSpellActive()const
        {
            return fireSpellActive;
        }

        bool isAcidCloudSpellActive()const
        {
            return acidCloudSpellActive;
        }

        bool isLightNingSpellActive()const
        {
            return lightningSpellActive;
        }

        void setGamePaused(bool pause)
        {
            gamePaused=pause;
        }

        void setNumberOfEnemiesSpawn(int spawn)
        {
            numberOfEnemiesSpawned=spawn;
        }

        void setFireActive(bool value)
        {
            this->fireSpellActive=value;
        }

        void setAcidCloudActive(bool value)
        {
            this->acidCloudSpellActive=value;
        }

        void setLightningActive(bool value)
        {
            this->lightningSpellActive=value;
        }


    protected:

    private:
        /** on fait une AIP car pour nous le joueur(player) ainsi que la carte(map)
        ne sont pas acccessible autre part que via le jeu (game) */
        Player *player;
        Map *mapOfGame;
        const int numberOfEnemies = 10;
        int numeroOfWave;
        int gameSpeed;
        bool gamePaused;
        bool fireSpellActive;
        bool acidCloudSpellActive;
        bool lightningSpellActive;
        int numberOfEnemiesSpawned;


};

#endif // GAME_H
