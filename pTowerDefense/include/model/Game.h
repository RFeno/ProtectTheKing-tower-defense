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
        void play();
        bool isGameOver();
        void createWave();
        void startWave();
        void animeEnemies();
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

        void setNumberOfEnemies(int number)
        {
            numberOfEnemies = number;
        }

        int getNumeroOfWave()
        {
            return numeroOfWave;
        }

    protected:

    private:
        Player *player;
        Map *mapOfGame;
        int numberOfEnemies;
        int numeroOfWave;
        const int WALK_SPEED = 2;


};

#endif // GAME_H
