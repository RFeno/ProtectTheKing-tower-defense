#ifndef SHADOWMONSTER_H
#define SHADOWMONSTER_H

#include <Enemies.h>


class ShadowMonster : public Enemies
{
    public:
        ShadowMonster();
        virtual ~ShadowMonster();
        ShadowMonster(const ShadowMonster& other);
        ShadowMonster& operator=(const ShadowMonster& other);
        ShadowMonster* clone()const;

    protected:

    private:
};

#endif // SHADOWMONSTER_H
