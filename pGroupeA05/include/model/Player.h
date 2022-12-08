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
        Player *clone()const;
        void buySpell(TypeOfSpell type);
        int searchSpellByType(TypeOfSpell type);
        bool removeSpell(TypeOfSpell type);
        bool activeSpell(TypeOfSpell type);
        void addScore(int score);
        void updateSpellsNumber();
        void clearListOfSpells();

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

         int getAcidNumber()
        {
            return acidNumber;
        }

        int getFireNumber()
        {
            return fireNumber;
        }

        int getLightningNumber()
        {
            return lightningNumber;
        }
        void setAcidNumber(int acidNumber)
        {
            if(acidNumber>=0)
            {
                this->acidNumber=acidNumber;
            }
        }
        void setFireNumber(int fireNumber)
        {
            if(fireNumber>=0)
            {
                this->fireNumber=fireNumber;
            }
        }
        void setLightningNumber(int lightningNumber)
        {
            if(lightningNumber>=0)
            {
                this->lightningNumber=lightningNumber;
            }
        }

    protected:

    private:
        //attributes
        int coins;
        int score;

        //AIP because spell are managed and accesible by only the player
        std::vector<Spell*> listOfSpells;
        int acidNumber = 0;
        int fireNumber = 0;
        int lightningNumber = 0;
        int numberOfEnemyKilled = 0;



};

#endif // PLAYER_H
