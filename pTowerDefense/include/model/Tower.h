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


class Tower
{
    public:
        Tower(int xTower=0, int yTower=0, int damage=20,int level=1,int price=100, int range=20);

        virtual ~Tower();

        Tower(const Tower& other);
        Tower& operator=(const Tower& rhs);

        //methods
        bool improveLevel();
        bool isInRange(int xOfEnemy,int xOfTower);
        void attackEnemy(Enemies &cible)const;
        std::string toString()const;

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

        void setX(int x)
        {
            this->xTower = x;
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
        int xTower;
        int yTower;
        int damage;
        int level;
        int price;
        int range;
        TypeOfTower type;

    private:

};

#endif // TOWER_H
