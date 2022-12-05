#ifndef SHADOWMONSTER_H
#define SHADOWMONSTER_H

#include <Enemies.h>


class ShadowMonster : public Enemies
{
    public:
        ShadowMonster(int health=300, int marketValue=10, int scoreValue=400, int damage=1,float walkingSpeed=1.15);
        virtual ~ShadowMonster();
        ShadowMonster(const ShadowMonster& other);
        ShadowMonster& operator=(const ShadowMonster& other);
        std::string getInformations()const;

    protected:

    private:
};

#endif // SHADOWMONSTER_H
