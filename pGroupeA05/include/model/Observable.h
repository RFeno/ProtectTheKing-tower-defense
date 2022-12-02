#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <Observer.h>
#include <vector>
class Observable
{
    public:
        //constructors
        Observable();

        //methods
        void addObs(Observer* obs);
        void deleteObs(Observer* obs);
        void notify();
        int searchObs(Observer* obs);

        //destructors
        virtual ~Observable();
        Observable(const Observable& other);
        Observable& operator=(const Observable& other);

    protected:

    private:
       std::vector<Observer*> listOfObserver;
};

#endif // OBSERVABLE_H
