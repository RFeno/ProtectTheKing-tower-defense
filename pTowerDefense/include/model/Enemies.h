#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>

enum typeOfEnemies : int
{
    gremlinValue = 20,
    knightOfDeathValue = 100,
    ogreValue = 80,
    orcValue =60,
    shadowMonsterValue = 40,
};

class State;
class King;

class Enemies
{
    public:

        static inline int compteur = 0;

        //canonic form
        Enemies(int health=100, int attackSpeed=1, int marketValue=100, int scoreValue=100, int damage=1, State *state=nullptr);
        virtual ~Enemies();
        Enemies(const Enemies& other);
        Enemies& operator=(const Enemies& other);

        //methods
        void attackKing(King &king);
        void walk(int x);
        void receiveDamage(int damage);
        void changeState(State *state);
        void die();

        //virtual Enemies* clone()const =0;

        //getters and setters
        void setHealth(int health);


        int getHealth()const
        {
            return health;
        }

        void setX(int x)
        {
            this->x = x;
        }

        void setY(int y)
        {
            this->y = y;
        }

        std::string getInformations()const;



        //to make it available in subclasses
    protected:
        int health;
        double attackSpeed;
        int marketValue;
        int scoreValue;
        int damage;
        int x = 0;
        int y = 0;
        int *id;
        State *state;


    private:


};

#endif // ENEMIES_H
