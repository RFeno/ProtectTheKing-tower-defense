#include "ShadowMonster.h"
#include <string.h>

using namespace std;

ShadowMonster::ShadowMonster(int health, int marketValue, int scoreValue, int damage,float walkingSpeed):Enemies(health,marketValue,scoreValue,damage,walkingSpeed)
{
    //ctor
    y=535;
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

    Enemies::operator=(rhs);

    //assignment operator
    return *this;
}


string ShadowMonster::getInformations()const
{
    return "[id: "+ to_string(*id)+ "      |ShadowMonster x:"+ to_string(x) +"    health:" + to_string(health) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) +"  walking speed:"+to_string(walkingSpeed) + " ]";
}

