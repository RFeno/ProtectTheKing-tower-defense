#include "ShadowMonster.h"
#include <string.h>

using namespace std;

ShadowMonster::ShadowMonster(int health, int attackSpeed, int marketValue, int scoreValue, int damage):Enemies(health,attackSpeed,marketValue,scoreValue,damage)
{
    //ctor
}

ShadowMonster::~ShadowMonster()
{
    //dtor
}

ShadowMonster::ShadowMonster(const ShadowMonster& other):Enemies(other)
{
    //copy ctor
}

ShadowMonster& ShadowMonster::operator=(const ShadowMonster& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

ShadowMonster* ShadowMonster::clone()const
{
    return new ShadowMonster(*this);
}

string ShadowMonster::getInformations()const
{
    return "[ShadowMonster x:"+ to_string(x) +"    health:" + to_string(health) + " attackSpeed:" + to_string(attackSpeed) + " market value:" + to_string(marketValue) + " score value:" + to_string(scoreValue) + "]";
}

