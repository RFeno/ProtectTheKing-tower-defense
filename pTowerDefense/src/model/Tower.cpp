#include "Tower.h"
#include <Enemies.h>
#include <stdexcept>
#include <iostream>

using namespace std;

Tower::Tower(int xTower, int yTower, int damage, int level, int price,int range): xTower(xTower), yTower(yTower), damage(damage), level(level), price(price), range(range)
{
    //ctor
    if(level<=0)
    {
        throw runtime_error("The level of tower cannot be below one");
    }

    if(price<=0)
    {
        throw runtime_error("The price of tower cannot be below or egal to 0");
    }

    if(damage<=0)
    {
        throw runtime_error("The damage of tower cannot be below or egal to 0");
    }

}

Tower::~Tower()
{
    //dtor
}

Tower::Tower(const Tower& other)
{
    //copy ctor
}

Tower& Tower::operator=(const Tower& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*return if the enemy is in range of the tower*/
bool Tower::isInRange(int xOfEnemy, int middleOfTower)
{
    int calcul = (xTower + middleOfTower) - xOfEnemy ;

    if(abs(calcul) <= range  )
    {
        return true;
    }
    return false;
}

/* the tower attack the enemies cible */
void Tower::attackEnemy(Enemies& target)const
{
    target.receiveDamage(damage);
}
/* improve the level of the tower (increase damage */
bool Tower::improveLevel()
{
    if(level+1 <= 3)
    {
        level++;
        return true;
    }
    cout << "the tower canno't be improve above level 3" << endl;
    return false;
}
/* show the state of the tower */
string Tower::toString()const
{
    return "[Tower: damage=> " + to_string(damage) + " level=>" + to_string(level) + " price=>"+ to_string(price) + " range:"+ to_string(range) + " x:" + to_string(xTower)+ "]";
}
