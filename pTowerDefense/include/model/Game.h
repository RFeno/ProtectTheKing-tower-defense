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
        void startWave(int numberOfEnemies);
        bool endWave();

        virtual ~Game();
        Game(const Game& other);
        Game& operator=(const Game& other);

    protected:

    private:
        Player player;
        King king;
        Map mapOfGame;
        int numberOfEnemies;
};

#endif // GAME_H
