#ifndef LINKEDLISTENUMERATOR_H
#define LINKEDLISTENUMERATOR_H

#include "Enumerator.h"
#include "ListNode.h"

template <typename T>
class LinkedListEnumerator : public Enumerator<T>
{
private:
	ListNode<T> *_current_node;
public:

	LinkedListEnumerator(ListNode<T> *front)
	{
		_current_node = front;
	}

	//increments the position in our list of nodes
	//and returns the new node's value
	virtual void next()
	{
		if (isFinished() == false)
		{
			_current_node = _current_node->getNext();
		}
	}

	virtual bool isFinished() const
	{
		return _current_node == nullptr;
	}

	//returns the current node's value
	virtual T *getValue()
	{
		return &_current_node->getValue();
	}
};

#endif