#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>

class Enemies
{
    public:

        static inline int compteur = 0;

        //canonic form
        Enemies(int health=100, int attackSpeed=1, int marketValue=100, int scoreValue=100, int damage=1);
        virtual ~Enemies();
        Enemies(const Enemies& other);
        Enemies& operator=(const Enemies& other);


        //methods
        void attackTower();
        void die();
        void walk();
        void receiveDamage(int damage);
        virtual Enemies* clone()const =0;


        //getters and setters
        void setHealth(int health)
        {
            this->health=health;

            if(health<0)
            {
                health=0;
            }
        }

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

    private:


};

#endif // ENEMIES_H
