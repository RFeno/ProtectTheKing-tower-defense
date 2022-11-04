#ifndef TOWER_H
#define TOWER_H
#include <Enemies.h>

/* classe abstraite */
enum TypeOfTower : int
{
    sand = 100,
    ice = 150,
    earth = 250,
    iron = 400
};

class Tower
{
    public:
        Tower(int damage=20,int level=1,int price=100);

        virtual ~Tower();

        Tower(const Tower& other);

        //methods
        bool improveLevel();
        void attackEnemy(Enemies &cible)const;
        std::string toString()const;
        //all child must to implement
        virtual Tower* clone()const =0;

        //getters and setters
        void setDamage(int damage)
        {
            this->damage=damage;
        }

        void setLevel(int level)
        {
            if(level<=0)
                this->level=level;
        }

        int getDamage()
        {
            return damage;
        }

        int getLevel()
        {
            return level;
        }

        int getPrice()
        {
            return price;
        }

        void setPrice(int price)
        {
            if(price < 0)
                this->price=price;
        }

        void setType(TypeOfTower type)
        {
            this->type=type;
        }

        TypeOfTower getType()
        {
            return type;
        }


    protected:

    private:
        int damage;
        int level;
        int price;
        TypeOfTower type;
};

#endif // TOWER_H
