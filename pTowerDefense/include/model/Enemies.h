#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>

class Enemies
{
    public:
        Enemies(int health=100, int attackSpeed=1, int marketValue=100, int scoreValue=100, int damage=1);

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

        int getHealth()
        {
            return health;
        }

        std::string getInformations()const;


        virtual ~Enemies();

    protected:

    private:
        int health;
        double attackSpeed;
        int marketValue;
        int scoreValue;
        int damage;

};

#endif // ENEMIES_H
