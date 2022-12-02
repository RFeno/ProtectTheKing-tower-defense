#include "Gremlin.h"
#include "Enemies.h"
#include <string.h>

using namespace std;

Gremlin::Gremlin(int health, int marketValue, int scoreValue, int damage,float walkingSpeed):Enemies(health,marketValue,scoreValue,damage,walkingSpeed)
{
    //ctor
    y=555;
}

Gremlin::~Gremlin()
{
    //dtor
}

Gremlin::Gremlin(const Gremlin& other):Enemies(other)
{
    //copy ctor
}

Gremlin& Gremlin::operator=(const Gremlin& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    Enemies::operator=(rhs);

    //assignment operator
    return *this;
}

/* return the state(informations of enemy */
string Gremlin::getInformations()const
{
    return "[id: "+ to_string(*id)+ "      |Gremlin       x:"+ to_string(x) +"    health:" + to_string(health) + "    market value:" + to_string(marketValue) + "     score value:" + to_string(scoreValue) +"  walking speed:"+to_string(walkingSpeed) + " ]";
}
