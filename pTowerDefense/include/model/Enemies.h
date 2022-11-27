#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>

#include "State.h"
#include "King.h"

class State;

enum typeOfEnemies : int
{
    gremlinValue = 20,
    knightOfDeathValue = 100,
    ogreValue = 80,
    orcValue =60,
    shadowMonsterValue = 40,
};



class Enemies
{
    public:

        static inline int compteur = 0;
        const int WALK_SPEED = 1;

        //canonic form
        Enemies(int health=100, int attackSpeed=1, int marketValue=100, int scoreValue=100, int damage=1);
        virtual ~Enemies();
        Enemies(const Enemies& other);
        Enemies& operator=(const Enemies& other);

        //methods
        void attackKing(King &king);
        void walk();
        void receiveDamage(int damage);
        void changeState(State *state);
        void die();

        //getters and setters
        void setHealth(int health);
        void setX(int x);

        int getHealth()const
        {
            return health;
        }

        int getX()const
        {
            return x;
        }

        int getY()const
        {
            return y;
        }

        int getId()const
        {
            return *id;
        }

        int getDamage()const
        {
            return damage;
        }

        bool isSpawn()const
        {
            return spawn;
        }

        void setSpawn(bool spawn)
        {
            this->spawn=spawn;
        }

        void setY(int y)
        {
            this->y = y;
        }

        State* getState()const
        {
            return state;
        }

        virtual std::string getInformations()const = 0 ;


    protected:

        //to make it available in subclasses
        int health;
        double attackSpeed;
        int marketValue;
        int scoreValue;
        int damage;
        bool spawn = false;

        int x = -40;
        int y;
        int *id;
        State *state;

    private:

};

#endif // ENEMIES_H
