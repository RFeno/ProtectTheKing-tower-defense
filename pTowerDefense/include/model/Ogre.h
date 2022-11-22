#ifndef OGRE_H
#define OGRE_H

#include <Enemies.h>


class Ogre : public Enemies
{
    public:
        Ogre(int health=800, int attackSpeed=1, int marketValue=800, int scoreValue=800, int damage=1);
        virtual ~Ogre();
        Ogre(const Ogre& other);
        Ogre& operator=(const Ogre& other);
        Ogre* clone()const;
        std::string getInformations()const;

    protected:

    private:
};

#endif // OGRE_H
