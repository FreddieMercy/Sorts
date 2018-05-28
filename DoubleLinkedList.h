#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H

#include <stdexcept>
#include "Indexed.h"
#include "ListNode.h"
#include "LinkedListEnumerator.h"
#include <utility>
#include "DoubleLinkNode.h"
using namespace std;

template <typename T>
class DoubleLinkedList : public LinkedList<T>
{
protected:

	//int _last_index_access = 0;
	//LinkNode<T> *_last_accessed_node = nullptr;

	DoubleLinkNode<T> *_front = nullptr;
	DoubleLinkNode<T> *_end = nullptr;
	//int _size = 0;

	virtual /*Double*/ListNode<T> *getNodeAtIndex(int index)
	{

		if (index < 0 || index >= getSize())
		{
			throw out_of_range("Invalid index.");
		}

		ListNode<T> *starting_node = _front;
		if (index >= _last_index_access)
		{
			starting_node = _last_accessed_node;
		}

		int counter = 0;
		ListNode<T> *current = _front;
		DoubleLinkNode<T> *currant = nullptr;
		while (/*counter < index && */current != nullptr)
		{
			currant->setPrevious(current);
			current = current->getNext();
			counter++;
		}

		_last_index_access = index;
		_last_accessed_node = current;

		return current;

	}

	virtual const /*Double*/ListNode<T> *getNodeAtIndex(int index) const
	{
		if (index < 0 || index >= getSize())
		{
			throw out_of_range("Invalid index.");
		}

		int counter = 0;
		ListNode<T> *current = _front;
		DoubleLinkNode<T> *currant = nullptr;
		while (/*counter < index &&*/ current != nullptr)
		{
			currant->setPrevious(current);
			current = current->getNext();
			counter++;
		}

		return current;
	}

public:

	virtual void addElement(T value)
	{
		if (_end == nullptr)
		{
			addElementAt(value, 0);
		}
		else
		{
			DoubleLinkNode<T> *new_node = new DoubleLinkNode<T>{ value };
			//_end->setPrevious(_end);
			new_node->setPrevious(_end);
			//end->setValue(new_node->getValue());
			_end->setNext(new_node);
			_end->setValue(_end->getNext());
			_size++;
		}
	}

	virtual T& getElementAt(int location)
	{

		return getNodeAtIndex(location)->getValue();
	}

	virtual const T &getElementAt(int location) const
	{
		return getNodeAtIndex(location)->getValue();
	}


	virtual void setElementAt(T value, int location)
	{
		getNodeAtIndex(location)->setValue(value);
	}

	//======================================================================

	virtual void addElementAt(T value, int location)
	{
		DoubleLinkNode<T> *new_value = new DoubleLinkNode<T>{ value };


		if (location == 0)
		{
			//new_value->setPrevious(_front->getPrevious());
			new_value->setNext(_front);
			_front = new_value;
			if (_end == nullptr)
			{
				_end = _front;
			}
		}
		else
		{
			ListNode<T> *parent = getNodeAtIndex(location - 1);
			ListNode<T> *old_child = parent->getNext();
			parent->setNext(new_value);
			new_value->setNext(old_child);
		}

		if (_end != nullptr && _end->getNext() != nullptr)
		{
			_end = _end->getNext();
		}

		if (_size > location)
		{
			_size++;
		}
		else
		{
			_size = location + 1;
		}
	}

	virtual void removeElementAt(int index)
	{
		if (index > 0)
		{
			ListNode<T> *before = getNodeAtIndex(index - 1);
			ListNode<T> *us = before->getNext();
			before->setNext(us->getNext());
			delete us;
		}
		else if (index == 0)
		{
			if (_front != nullptr)
			{
				ListNode<T> *temp = _front;
				_front = temp->getNext();
				delete temp;
			}
			else
			{
				throw out_of_range("Index out of bounds.");
			}
		}
		else
		{

		}

		_size--;
	}

	//virtual Enumerator<T> *getEnumerator() const
	//{
	//	return new LinkedListEnumerator<T>(_front);
	//}

};

#endif