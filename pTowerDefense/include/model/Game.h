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

    protected:

    private:
        Player *player;
        Map *mapOfGame;
        const int numberOfEnemies =10;
        int numeroOfWave =0;


};

#endif // GAME_H
