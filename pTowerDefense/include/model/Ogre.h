#ifndef OGRE_H
#define OGRE_H

#include <Enemies.h>


class Ogre : public Enemies
{
    public:
        Ogre(int health=800, int marketValue=800, int scoreValue=800, int damage=1,float walkingSpeed=0.9);
        virtual ~Ogre();
        Ogre(const Ogre& other);
        Ogre& operator=(const Ogre& other);
        std::string getInformations()const;

    protected:

    private:
};

#endif // OGRE_H
