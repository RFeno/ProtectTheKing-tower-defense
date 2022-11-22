#ifndef SHADOWMONSTER_H
#define SHADOWMONSTER_H

#include <Enemies.h>


class ShadowMonster : public Enemies
{
    public:
        ShadowMonster(int health=400, int attackSpeed=1, int marketValue=400, int scoreValue=400, int damage=1);
        virtual ~ShadowMonster();
        ShadowMonster(const ShadowMonster& other);
        ShadowMonster& operator=(const ShadowMonster& other);
        ShadowMonster* clone()const;
        std::string getInformations()const;

    protected:

    private:
};

#endif // SHADOWMONSTER_H
