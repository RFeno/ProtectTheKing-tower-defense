#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include <Spell.h>
#include <Tower.h>
#include <iostream>
#include <string>

class Player
{
    public:

        //constructors
        Player(std::string name="Anonymous",int coins = 100,int score = 0);
        //destructor
        virtual ~Player();
        Player& operator=(const Player& rhs);

        //methods
        void buyTower(TypeOfTower type);
        void buySpell();
        void placeTower(Tower tower);
        void sellTower();
        void improveTower(Tower tower);
        void activeSpell();
        void addScore(int score);

        //getters and setters
        std::string getName()const
        {
            return name;
        }

        void setName(std::string name)
        {
            this->name=name;
        }

        int getCoins()const
        {
            return coins;
        }

        void setCoins(int coins)
        {
            if(coins>=0)
                this->coins=coins;
        }

        int getScore()
        {
            return score;
        }

        void setScore(int score)
        {
            if(score<=0)
            {
                this->score=score;
            }
        }

    protected:

    private:
        //attributes
        std::string name;
        int coins;
        int score;
        std::list<Spell*> listOfSpells;


};

#endif // PLAYER_H
