#include "KnightOfDeath.h"
#include <string>
using namespace std;
KnightOfDeath::KnightOfDeath(int health, float attackSpeed, int marketValue, int scoreValue, int damage,float walkingSpeed):Enemies(health,attackSpeed,marketValue,scoreValue,damage,walkingSpeed)
{
    //ctor
    y=493;
}

KnightOfDeath::~KnightOfDeath()
{
    //dtor
}

KnightOfDeath::KnightOfDeath(const KnightOfDeath& other):Enemies(other)
{
    //copy ctor
}

KnightOfDeath& KnightOfDeath::operator=(const KnightOfDeath& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Enemies::operator=(rhs);
    //assignment operator
    return *this;
}

string KnightOfDeath::getInformations()const
{
    return "[id: "+ to_string(*id)+ "      |KnightOfDeath x:"+ to_string(x) +"    health:" + to_string(health) + "    attackSpeed:" + to_string(attackSpeed) + "    market value:" + to_string(marketValue) + "    score value:" + to_string(scoreValue) +" walking speed:"+to_string(walkingSpeed) + "]";
}
