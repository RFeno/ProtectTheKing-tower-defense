#include "Tower.h"
#include <Enemies.h>
#include <stdexcept>
#include <iostream>

using namespace std;

Tower::Tower(int xTower, int yTower, int damage, int level, int price,int range,int position): xTower(xTower), yTower(yTower), damage(damage), level(level), price(price), range(range), position(position)
{
    //ctor
    if(level<=0)
    {
        cerr << "The level of tower cannot be below one" << endl;
    }

    if(price<=0)
    {
        cerr << "The price of tower cannot be below or egal to 0" << endl;
    }

    if(damage<=0)
    {
        cerr << "The damage of tower cannot be below or egal to 0" << endl;
    }

    this->attackActivated=false;
    type=none;

}

Tower::~Tower()
{
    //dtor
}

Tower::Tower(const Tower& other): xTower(other.xTower), yTower(other.yTower), damage(other.damage), level(other.level), price(other.price), range(other.range), position(other.position), attackActivated(other.attackActivated)
{
    //copy ctor
    this->type=other.type;
}

Tower& Tower::operator=(const Tower& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->damage=rhs.damage;
    this->level=rhs.level;
    this->price=rhs.price;
    this->range=rhs.range;
    this->xTower=rhs.xTower;
    this->yTower=rhs.yTower;
    this->type=rhs.type;
    this->position=rhs.position;
    this->attackActivated=rhs.attackActivated;

    //assignment operator
    return *this;
}

/** return if the enemy is in range of the tower*/
bool Tower::isInRange(int xOfEnemy, int middleOfTower)
{
    int calcul = (xTower + middleOfTower) - xOfEnemy ;

    if(abs(calcul) <= range)
    {
        return true;
    }
    return false;
}

/** the tower attack the enemies cible */
void Tower::attackEnemy(Enemies& target)const
{
    target.receiveDamage(damage);
}

/** improve the level of the tower (increase damage */
bool Tower::improveLevel()
{
    if(level+1 <= 3)
    {
        level++;
        return true;
    }
    else
    {
        cout << "the tower canno't be improve above level 3" << endl;
        return false;
    }
}

/** show the state of the tower */
string Tower::toString()const
{
    return "[Tower: damage=> " + to_string(damage) + " position: "+ to_string(position) + " level=>" + to_string(level) + " price=>"+ to_string(price) + " range:"+ to_string(range) + " x:" + to_string(xTower)+ "]";
}
