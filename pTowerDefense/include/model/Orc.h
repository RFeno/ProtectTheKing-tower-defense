#ifndef ORC_H
#define ORC_H

#include <Enemies.h>


class Orc : public Enemies
{
    public:
        Orc(int health=60, int attackSpeed=1, int marketValue=60, int scoreValue=60, int damage=1);
        virtual ~Orc();
        Orc(const Orc& other);
        Orc& operator=(const Orc& other);
        Orc* clone()const;

    protected:

    private:
};

#endif // ORC_H
