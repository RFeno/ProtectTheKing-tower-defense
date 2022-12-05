#ifndef TOWER_H
#define TOWER_H
#include <Enemies.h>


enum TypeOfTowerPrice : int
{
    sand = 100,
    earth = 150,
    ice = 250,
    iron = 400
};


class Tower
{
    public:
        Tower(int xTower=0, int yTower=0, int damage=20,int level=1,int price=100, int range=20,int position=-1);
        virtual ~Tower();
        Tower(const Tower& other);
        Tower& operator=(const Tower& rhs);

        //methods
        bool improveLevel();
        void improveStatistics();
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
            {
                this->level=level;
            }
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
            {
                this->price=price;
            }
        }

        void setType(TypeOfTowerPrice type)
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

        int getPosition()
        {
            return position;
        }

        void setPosition(int position)
        {
            this->position=position;
        }

        TypeOfTowerPrice getType()
        {
            return type;
        }

        bool isAttacking()
        {
            return attackActivated;
        }

        void setAttacking(bool activated)
        {
            this->attackActivated=activated;
        }


    protected:
        int xTower;
        int yTower;
        int damage;
        int level;
        int price;
        int range;
        TypeOfTowerPrice type;
        int position;
        bool attackActivated;

    private:

};

#endif // TOWER_H
