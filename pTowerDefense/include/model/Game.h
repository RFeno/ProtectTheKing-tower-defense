#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player.h"
#include "King.h"
#include "Map.h"

class Game
{
    public:
        Game(std::string nameOfPlayer);

        //mehtods
        void play();
        bool gameOver();
        void createWave(int numberOfEnemies);
        void startWave();
        void ennemiesWalk();
        void TowerAttack();
        bool endWave();

        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

        Map* getMap()const
        {
            return mapOfGame;
        }



    protected:

    private:
        Player *player;
        King *king;
        Map *mapOfGame;
        int numberOfEnemies;

};

#endif // GAME_H
