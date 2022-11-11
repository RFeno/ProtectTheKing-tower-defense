#ifndef OGRE_H
#define OGRE_H

#include <Enemies.h>


class Ogre : public Enemies
{
    public:
        Ogre(int health=60, int attackSpeed=1, int marketValue=60, int scoreValue=60, int damage=1);
        virtual ~Ogre();
        Ogre(const Ogre& other);
        Ogre& operator=(const Ogre& other);
        Ogre* clone()const;

    protected:

    private:
};

#endif // OGRE_H
