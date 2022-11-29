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

        //canonic form
        Enemies(int health=100, int marketValue=100, int scoreValue=100, int damage=1,float walkingSpeed=1.0);
        virtual ~Enemies();
        Enemies(const Enemies& other);
        Enemies& operator=(const Enemies& other);

        //methods
        void attackKing(King &king);
        void walk();
        void receiveDamage(int damage);
        void changeState(State *state);
        void die();
        void improveStatistics(int numeroOfWave);

        //getters and setters
        void setHealth(int health);
        void setX(float x);

        int getHealth()const
        {
            return health;
        }

        float getX()const
        {
            return x;
        }

        float getY()const
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

        int getHealthMax()
        {
            return healthMax;
        }

        float getWalkingSpeed()
        {
            return walkingSpeed;
        }

        bool isSpawn()const
        {
            return spawn;
        }

        void setWalkingSpeed(float speed);

        void setSpawn(bool spawn)
        {
            this->spawn=spawn;
        }

        void setY(float y)
        {
            this->y = y;
        }

        State* getState()const
        {
            return state;
        }

        virtual std::string getInformations()const = 0 ;


    protected:

        //real health
        int health;

        //only change when the enemy is improved
        int healthMax;

        //the money the player earns when this enemy is killed
        int marketValue;

        //the score the player gains when this enemy is killed
        int scoreValue;

        //damage at each attack
        int damage;

        //if the enemy is visible on the screen (given that they start walking at -40)
        bool spawn = false;

        float walkingSpeed;


        //enemies start at -40 to arrive naturally on the screen
        float x = -40;
        float y;
        int *id;
        State *state = nullptr;

    private:

};

#endif // ENEMIES_H
