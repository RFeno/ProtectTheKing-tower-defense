#ifndef KING_H
#define KING_H

class King
{
    public:

        King(int health=1000);
        virtual ~King();
        King(const King& other);
        King& operator=(const King& other);

        int getHealth()
        {
            return health;
        }

        void setHealth(int health);
        void receiveDamage(int damage);



    protected:

    private:
        int health;
};

#endif // KING_H
