#ifndef OGRE_H
#define OGRE_H

#include <Enemies.h>


class Ogre : public Enemies
{
    public:
        Ogre();
        virtual ~Ogre();
        Ogre(const Ogre& other);
        Ogre& operator=(const Ogre& other);
        Ogre* clone()const;

    protected:

    private:
};

#endif // OGRE_H
