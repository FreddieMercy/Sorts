#ifndef COLLECTION_H
#define COLLECTION_H

//Collection is the most basic form of ADT that we will use.
template<typename T>
class Collection
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getSize() const = 0;
};

#endif