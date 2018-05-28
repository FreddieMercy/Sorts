#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "Indexed.h"
#include "ListNode.h"
#include "LinkedListEnumerator.h"
#include <utility>
using namespace std;

template <typename T>
class LinkedList : public Indexed<T>
{
private:
	
protected:

	//keeps track of the last item accessed in the linked list
	int _last_index_access = 0;
	ListNode<T> *_last_accessed_node = nullptr;

	ListNode<T> *_front = nullptr;
	ListNode<T> *_end = nullptr;
	int _size = 0;

	//can be used to return a ListNode<T> at a specific
	//index.
	virtual ListNode<T> *getNodeAtIndex(int index)
	{
		//check to see if index is valid
		if (index < 0 || index >= getSize())
		{
			throw out_of_range("Invalid index.");
		}

		//which is closer: last accessed or the front?
		ListNode<T> *starting_node = _front;
		if (index >= _last_index_access)
		{
			starting_node = _last_accessed_node;
		}

		//keeps track of where we're at in our LL
		int counter = 0;
		ListNode<T> *current = _front;
		while (counter < index && current != nullptr)
		{
			current = current->getNext();
			counter++;
		}

		_last_index_access = index;
		_last_accessed_node = current;

		//return desired node
		return current;
	}

	//constant version of the above code
	virtual const ListNode<T> *getNodeAtIndex(int index) const
	{
		//check to see if index is valid
		if (index < 0 || index >= getSize())
		{
			throw out_of_range("Invalid index.");
		}

		//keeps track of where we're at in our LL
		int counter = 0;
		ListNode<T> *current = _front;
		while (counter < index && current != nullptr)
		{
			current = current->getNext();
			counter++;
		}

		//return desired node
		return current;
	}

public:

#pragma region constructor - destructor - operator=
	LinkedList()
	{
		_front = nullptr;
		_end = _front;
	}

	//copy constructor
	LinkedList(const LinkedList<T> &other)
	{
		//TODO: Implement copy constructor
	}

	//Always remeber to clean up pointers in destructor
	~LinkedList()
	{
		ListNode<T> *current = _front;
		ListNode<T> *next = nullptr;
		while (current != nullptr)
		{
			next = current->getNext();
			delete current;
			current = next;
		}
	}

	LinkedList<T> &operator=(const LinkedList<T> &other)
	{
		//TODO: Implement copy operator=
	}
#pragma endregion

#pragma region Collection overrides

	//will return true if the LL is empty.
	virtual bool isEmpty() const
	{
		return _front == nullptr;
	}

	//returns the size of the LL.
	virtual int getSize() const
	{
		return _size;
	}

#pragma endregion

#pragma region Bag overrides

	//adds the supplied item to the end of our LL
	virtual void addElement(T value)
	{
		if (_end == nullptr)
		{
			addElementAt(value, 0);
		}
		else
		{
			ListNode<T> *new_node = new ListNode<T>{ value };
			_end->setNext(new_node);
			_end = _end->getNext();
			_size++;
		}
	}
#pragma endregion

#pragma region Indexed overrides

	//returns the value at the specified index
	virtual T& getElementAt(int location)
	{
		//explicit way
		//ListNode<T> *result = getNodeAtIndex(location);
		//return result->getValue();

		//shortcut
		return getNodeAtIndex(location)->getValue();
	}

	virtual const T &getElementAt(int location) const
	{
		return getNodeAtIndex(location)->getValue();
	}

	//sets the value at the specified index
	virtual void setElementAt(T value, int location)
	{
		getNodeAtIndex(location)->setValue(value);
	}

	//adds the specified item at the specified index and shifts everything else
	//to the "right" by one.
	virtual void addElementAt(T value, int location)
	{
		ListNode<T> *new_value = new ListNode<T>{ value };

		//Option #1: are we adding this to the front?
		if (location == 0)
		{
			new_value->setNext(_front);
			_front = new_value;
			if (_end == nullptr)
			{
				_end = _front;
			}
		}
		else
		{
			//Option #2: Adding somewhere else
			ListNode<T> *parent = getNodeAtIndex(location - 1);
			ListNode<T> *old_child = parent->getNext();
			parent->setNext(new_value);
			new_value->setNext(old_child);
		}

		//AC: does this work?
		if (_end != nullptr && _end->getNext() != nullptr)
		{
			_end = _end->getNext();
		}

		//increase max size
		if (_size > location)
		{
			_size++;
		}
		else
		{
			_size = location + 1;
		}
	}

	//removes the element at the specified index.
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
			//Note: we need to make sure that _front is not
			//null because calling ->getNext()  on a null
			//object will throw an exception
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
			//TODO: throw exception
		}

		//decrease max size
		_size--;
	}

#pragma endregion

#pragma region Linked-List specific

	//Returns an enumerator for faster access to LL items
	virtual Enumerator<T> *getEnumerator() const
	{
		return new LinkedListEnumerator<T>(_front);
	}

#pragma endregion
};

#endif // !LINKED_LIST_H
