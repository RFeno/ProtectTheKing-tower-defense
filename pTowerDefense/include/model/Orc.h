#ifndef ORC_H
#define ORC_H

#include <Enemies.h>


class Orc : public Enemies
{
    public:
        Orc();
        virtual ~Orc();
        Orc(const Orc& other);
        Orc& operator=(const Orc& other);
        Orc* clone()const;

    protected:

    private:
};

#endif // ORC_H
