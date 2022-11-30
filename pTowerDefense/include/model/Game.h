#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player.h"
#include "King.h"
#include "Map.h"

class Game
{
    public:
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

    protected:

    private:
        Player *player;
        Map *mapOfGame;
        const int numberOfEnemies =10;
        int numeroOfWave =0;
        int gameSpeed = 1;


};

#endif // GAME_H
