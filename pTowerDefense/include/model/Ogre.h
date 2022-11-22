#ifndef OGRE_H
#define OGRE_H

#include <Enemies.h>


class Ogre : public Enemies
{
    public:
        Ogre(int health=80, int attackSpeed=1, int marketValue=80, int scoreValue=80, int damage=1);
        virtual ~Ogre();
        Ogre(const Ogre& other);
        Ogre& operator=(const Ogre& other);
        Ogre* clone()const;

    protected:

    private:
};

#endif // OGRE_H
