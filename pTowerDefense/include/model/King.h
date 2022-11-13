#ifndef KING_H
#define KING_H
#include "Observable.h"

class King : public Observable
{
    public:
        King();
        virtual ~King();
        King(const King& other);
        King& operator=(const King& other);

        int getNumberOflives()
        {
            return numberOfLives;
        }



    protected:

    private:
        int numberOfLives;
};

#endif // KING_H
