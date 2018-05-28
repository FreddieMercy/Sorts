#ifndef BAG_H
#define BAG_H

#include "Collection.h"

//Bags allow items to be added to collections
template <typename T>
class Bag : public Collection<T>
{
public:

    //Note that it would probably be more efficient to pass by constant reference,
    //but for learning purposes, I'm sticking to pass by value.
	virtual void addElement(T item) = 0;
};

#endif