#ifndef PLAYER_H
#define PLAYER_H

#include "Spell.h"
#include "Tower.h"

#include <iostream>
#include <string>
#include <vector>

class Player
{
    public:
        //canonic form
        Player(int coins = sand,int score = 0);
        Player(const Player& other);
        virtual ~Player();
        Player& operator=(const Player& rhs);

        //methods
        void buySpell(TypeOfSpell type);
        int searchSpellByType(TypeOfSpell type);
        bool useAndRemoveSpell(TypeOfSpell type,std::vector<Enemies*> listOfEnemies);
        bool activeSpell(TypeOfSpell type,std::vector<Enemies*> listOfEnemies);
        void addScore(int score);

        //getters and setter
        int getCoins()const
        {
            return coins;
        }

         int getScore()const
        {
            return score;
        }

        int getNumberOfEnemyKilled()const
        {
            return numberOfEnemyKilled;
        }

        void setCoins(int coins)
        {
            if(coins>=0)
            {
                this->coins=coins;
            }
        }

        void setScore(int score)
        {
            if(score>=0)
            {
                this->score=score;
            }
        }

        void setNumberOfEnemyKilled(int numberOfEnemyKilled)
        {
            this->numberOfEnemyKilled=numberOfEnemyKilled;
        }

        std::vector<Spell*> getSpells()const
        {
            return listOfSpells;
        }

    protected:

    private:
        //attributes
        int coins;
        int score;
        int numberOfEnemyKilled = 0;
        std::vector<Spell*> listOfSpells;


};

#endif // PLAYER_H
