#ifndef ORC_H
#define ORC_H

#include <Enemies.h>


class Orc : public Enemies
{
    public:
        Orc(int health=350, int marketValue=12, int scoreValue=600, int damage=1,float walkingSpeed=1.2);
        virtual ~Orc();
        Orc(const Orc& other);
        Orc& operator=(const Orc& other);
        std::string getInformations()const;
        Orc* clone() const;

    protected:

    private:
};

#endif // ORC_H
