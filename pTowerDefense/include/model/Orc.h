#ifndef ORC_H
#define ORC_H

#include <Enemies.h>


class Orc : public Enemies
{
    public:
        Orc(int health=600, int attackSpeed=1, int marketValue=600, int scoreValue=600, int damage=1);
        virtual ~Orc();
        Orc(const Orc& other);
        Orc& operator=(const Orc& other);
        Orc* clone()const;
        std::string getInformations()const;

    protected:

    private:
};

#endif // ORC_H
