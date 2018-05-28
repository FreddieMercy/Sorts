#ifndef QUEUE_H
#define QUEUE_H

#include "Bag.h"

//Queues allow us to insert items at the end of our bag and remove from the front of the bag
template <typename T>
class Queue : public Bag<T>
{
public:
	virtual T &getFirst() = 0;
	virtual void enqueue(T item) = 0;
	virtual T dequeue() = 0;
};

#endif