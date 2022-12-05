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
    orcValue = 60,
    shadowMonsterValue = 40
};

enum sizeOfEnemies: int
{
    OGRE_WIDTH = 377,
    OGRE_HEIGHT = 404,
    ORC_WIDTH = 339,
    ORC_HEIGHT = 353,
    GREMLIN_WIDTH = 238,
    GREMLIN_HEIGHT = 227,
    SHADOWMONSTER_WIDTH = 326,
    SHADOWMONSTER_HEIGHT = 302,
    KNIGHTOFDEATH_WIDTH = 445,
    KNIGHTOFDEATH_HEIGHT = 469
};


class Enemies
{
    public:

        static inline int compteur = 0;
        static const int NUMBER_OF_ENEMY_TYPES = 5;

        Enemies(int health=100, int marketValue=100, int scoreValue=100, int damage=1,float walkingSpeed=1.0);
        virtual ~Enemies();
        Enemies(const Enemies& other);
        Enemies& operator=(const Enemies& other);

        ///methods
        void attackKing(King &king);
        void walk();
        void receiveDamage(int damage);
        void changeState(State *state);
        void die();
        void improveStatistics(int numeroOfWave);

        ///getters and setters
        void setHealth(int health);
        void setX(float x);
        void setWalkingSpeed(float speed);

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

        bool isCounted()const
        {
            return counted;
        }

        void setCounted(bool counted)
        {
            this->counted=counted;
        }

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

        int getMarketValue()
        {
            return marketValue;
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
        bool spawn;

        //if the enemy is already count for player score and coins
        bool counted;

        float walkingSpeed;

        float x;
        float y;

        int *id;

        State *state = nullptr;

        const float IMPROVE_LEVEL = 0.35;

    private:

};

#endif // ENEMIES_H
