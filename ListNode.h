#ifndef LISTNODE_H
#define LISTNODE_H
#include <utility>

template <typename T>
class ListNode
{
protected:
	T _value;
	ListNode<T> *_next;

public:
	ListNode(const T &value)
	{
		_value = value;
		_next = nullptr;
	}

	ListNode(const ListNode<T> &other)
	{
		_value = other.getValue();
		_next = other.getNext();
	}

	ListNode<T> &operator=(const ListNode<T> &other)
	{
		if(this != &other)
		{
			ListNode<T> temp(other);
			swap(*this, temp);
		}
		return *this;
	}

	ListNode<T> *getNext()
	{
		return _next;
	}

	void setNext(ListNode<T> *next)
	{
		_next = next;
	}

	T &getValue()
	{
		return _value;
	}

    const T& getValue() const
    {
        return _value;
    }

	virtual void setValue(const T &value)
	{
		_value = value;
	}
};

#endif