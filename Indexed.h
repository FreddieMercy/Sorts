#ifndef INDEXED_H
#define INDEXED_H

#include "Bag.h"

//Indexed ADTs allow items to be inserted at specific locations within a bag
template <typename T>
class Indexed : public Bag<T>
{
public:
    virtual T &getElementAt(int index) = 0;
    virtual const T& getElementAt(int location) const = 0;
    virtual void setElementAt(T item, int index) = 0;
    virtual void addElementAt(T item, int index) = 0;
    virtual void removeElementAt(int index) = 0;
};

#endif