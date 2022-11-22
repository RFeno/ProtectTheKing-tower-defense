#ifndef TOWER_H
#define TOWER_H
#include <Enemies.h>


enum TypeOfTower : int
{
    sand = 100,
    ice = 150,
    earth = 250,
    iron = 400
};
/* classe abstraite */
class Tower
{
    public:
        Tower(int damage=20,int level=1,int price=100);

        virtual ~Tower();

        Tower(const Tower& other);

        //methods
        bool improveLevel();
        bool isInRange(int xOfEnemy);
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

        int getX()
        {
            return xTower;
        }

        int getRange()
        {
            return range;
        }

        TypeOfTower getType()
        {
            return type;
        }


    protected:
        int damage;
        int level;
        int price;
        int range;
        int xTower;
        int yTower;

        TypeOfTower type;

    private:

};

#endif // TOWER_H
