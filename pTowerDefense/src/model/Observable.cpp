#include "Observable.h"

Observable::Observable()
{
    //ctor
}

Observable::~Observable()
{
    //dtor
}

Observable::Observable(const Observable& other)
{
    //copy ctor
}

Observable& Observable::operator=(const Observable& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Observable::addObs(Observer* obs)
{
    listOfObserver.push_back(obs);
}

void Observable::deleteObs(Observer* obs)
{
    int index = searchObs(obs);

    if(index != -1)
    {
        Observer * temp = listOfObserver[index];
        listOfObserver.erase(listOfObserver.begin() + index);
        delete temp;
    }

}

/* find index of the observer */
int Observable::searchObs(Observer* obs)
{

    for(std::size_t i = 0;i<listOfObserver.size(); i++)
     {
        if(obs == listOfObserver[i])
        {
            return i;
        }
     }
     return -1;
}

void Observable::notify()
{
    for(std::size_t i = 0; i<listOfObserver.size();i++)
    {
        //update this ?
        listOfObserver[i]->update(this);
    }
}

