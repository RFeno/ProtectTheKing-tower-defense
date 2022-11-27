#ifndef KING_H
#define KING_H

#include <string>

class King
{
    public:

        King(int health=10000);
        virtual ~King();
        King(const King& other);
        King& operator=(const King& other);

        const static int xKing = 1200;
        const static int kingHeathMax = 10000;

        int getHealth()
        {
            return health;
        }

        void setHealth(int health);
        void receiveDamage(int damage);

        std::string getInformations()const;



    protected:

    private:
        int health;

};

#endif // KING_H
