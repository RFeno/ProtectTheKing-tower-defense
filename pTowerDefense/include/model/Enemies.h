#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>

class Enemies
{
    public:

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

        std::string getInformations()const;



        //to make it available in subclasses
    protected:
        int health;
        double attackSpeed;
        int marketValue;
        int scoreValue;
        int damage;

    private:


};

#endif // ENEMIES_H
