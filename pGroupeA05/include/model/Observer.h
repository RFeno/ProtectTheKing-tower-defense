#ifndef OBSERVER_H
#define OBSERVER_H
//#include "Observable.h"
#include <vector>
//ask to teach why we need to use this for include
class Observable;

class Observer
{
    public:
        //constructors
        Observer();
        //methods
        void update(const Observable* obs);

        //destructors
        virtual ~Observer();
        //cp ctor
        Observer(const Observer& other);
        Observer& operator=(const Observer& other);

    protected:

    private:
        std::vector<Observable*> listOfObservable;

};

#endif // OBSERVER_H
