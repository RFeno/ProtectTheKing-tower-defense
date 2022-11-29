#ifndef KING_H
#define KING_H

#include <string>

class King
{
    public:

        King(int health=1000);
        virtual ~King();
        King(const King& other);
        King& operator=(const King& other);

        const static int xKing = 1200;


        int getHealth()
        {
            return health;
        }

        int getKingHealthMax()
        {
            return kingHealthMax;
        }

        void setHealth(int health);
        void receiveDamage(int damage);

        std::string getInformations()const;



    protected:

    private:
        int health;
        int kingHealthMax;

};

#endif // KING_H
