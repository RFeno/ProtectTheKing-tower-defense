#ifndef SHADOWMONSTER_H
#define SHADOWMONSTER_H

#include <Enemies.h>


class ShadowMonster : public Enemies
{
    public:
        ShadowMonster(int health=40, int attackSpeed=1, int marketValue=40, int scoreValue=40, int damage=1);
        virtual ~ShadowMonster();
        ShadowMonster(const ShadowMonster& other);
        ShadowMonster& operator=(const ShadowMonster& other);
        ShadowMonster* clone()const;

    protected:

    private:
};

#endif // SHADOWMONSTER_H
